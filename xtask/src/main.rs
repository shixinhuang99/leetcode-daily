use std::{env, fs, path::PathBuf};

use anyhow::Result;

fn main() {
    Xtask::try_new().unwrap().run().unwrap();
}

enum Action {
    Sol((String, String)),
    Clip(String),
    Reset,
}

struct Xtask {
    solved_dir: PathBuf,
    lib_rs_path: PathBuf,
    lib_rs_tpl_path: PathBuf,
    main_rs_path: PathBuf,
    main_rs_tpl_path: PathBuf,
    ts_sol_path: PathBuf,
    ts_sol_tpl_path: PathBuf,
}

impl Xtask {
    fn try_new() -> Result<Self> {
        let cwd = env::current_dir()?;
        let solved_dir = cwd.join("solved");
        let lib_rs_path = cwd.join("src").join("lib.rs");
        let lib_rs_tpl_path = cwd.join("templates").join("lib.rs.txt");
        let main_rs_path = cwd.join("src").join("main.rs");
        let main_rs_tpl_path = cwd.join("templates").join("main.rs.txt");
        let ts_sol_path = cwd.join("typescript").join("sol.ts");
        let ts_sol_tpl_path = cwd.join("templates").join("ts-sol.ts.txt");

        Ok(Self {
            solved_dir,
            lib_rs_path,
            lib_rs_tpl_path,
            main_rs_path,
            main_rs_tpl_path,
            ts_sol_path,
            ts_sol_tpl_path,
        })
    }

	fn run(&self) -> Result<()> {
		let action = parse_action();

        match action {
            Action::Sol((lang, name)) => self.sol(lang, name)?,
            Action::Clip(lang) => self.clip(lang)?,
            Action::Reset => self.reset()?,
        }

		Ok(())
	}

    fn sol(&self, lang: String, file_name: String) -> Result<()> {
        if lang == "all" || lang == "rs" {
            let pre_sol_code = fs::read_to_string(&self.lib_rs_path)?;
            let sol_code = filter_code(pre_sol_code);
            fs::write(
                self.solved_dir.join(format!("{file_name}.rs")),
                sol_code,
            )?;
        }

        if lang == "all" || lang == "ts" {
            let pre_sol_code = fs::read_to_string(&self.ts_sol_path)?;
            let sol_code = filter_code(pre_sol_code);
            fs::write(
                self.solved_dir.join(format!("{file_name}.ts")),
                sol_code,
            )?;
        }

        self.reset()?;

		Ok(())
	}

    fn clip(&self, lang: String) -> Result<()> {
        use std::{
            io::Write,
            process::{Command, Stdio},
            thread,
        };

        let sol_code = if lang == "rs" {
            fs::read_to_string(&self.lib_rs_path)?
        } else if lang == "ts" {
            fs::read_to_string(&self.ts_sol_path)?
        } else {
            panic!("unknown lang");
        };

		let mut sol_fn_code = String::new();
		let mut flag = false;

        for line in filter_code(sol_code).lines() {
            if line == "// start" {
                flag = true;
            } else if line == "// end" {
                break;
            } else if flag {
                sol_fn_code.push_str(line);
                sol_fn_code.push('\n');
            }
        }

		let cmd_name = if cfg!(target_os = "macos") {
			"pbcopy"
		} else if cfg!(target_os = "windows") {
			"clip"
		} else {
			panic!("unsupported os");
		};

		let mut cmd = Command::new(cmd_name).stdin(Stdio::piped()).spawn()?;

		let mut stdin = cmd
			.stdin
			.take()
			.ok_or(anyhow::anyhow!("failed to open stdin"))?;

		thread::spawn(move || -> Result<()> {
			stdin.write_all(sol_fn_code.as_bytes())?;
			Ok(())
		});

		cmd.wait()?;

		Ok(())
	}

    fn reset(&self) -> Result<()> {
        let lib_rs_tpl_code = fs::read_to_string(&self.lib_rs_tpl_path)?;
        let main_rs_tpl_code = fs::read_to_string(&self.main_rs_tpl_path)?;
        fs::write(&self.lib_rs_path, lib_rs_tpl_code)?;
        fs::write(&self.main_rs_path, main_rs_tpl_code)?;
        let ts_sol_tpl_code = fs::read_to_string(&self.ts_sol_tpl_path)?;
        fs::write(&self.ts_sol_path, ts_sol_tpl_code)?;

		Ok(())
	}
}

fn filter_code(code: String) -> String {
    let mut filtered_code = String::new();
    let ignore = ["//", "println!", "print!", "console.log"];
    let required = ["// start", "// end"];
    let mut last_line_empty = false;

    for line in code.lines() {
        let trimed = line.trim_start();
        if !required.contains(&trimed)
            && ignore.iter().any(|v| trimed.starts_with(v))
        {
            continue;
        }
        if !(last_line_empty && line.is_empty()) {
            filtered_code.push_str(line);
            filtered_code.push('\n');
        }
        last_line_empty = line.is_empty();
    }

    filtered_code
}

fn parse_action() -> Action {
	let args: Vec<String> = env::args().collect();

    if args.len() == 4 && args[1] == "sol" {
        return Action::Sol((
            args[2].to_string(),
            args[3].replace(|ch: char| !ch.is_ascii_alphanumeric(), "_"),
        ));
    }

    if args.len() == 3 && args[1] == "clip" {
        return Action::Clip(args[2].to_string());
    }

	if args.len() == 2 && args[1] == "reset" {
		return Action::Reset;
	}

	panic!("unknown action");
}
