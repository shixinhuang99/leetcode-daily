use anyhow::Result;
use std::{env, fs, path::PathBuf};

static LIB_TPL_CODE: &str = include_str!("lib.rs.txt");
static MAIN_TPL_CODE: &str = include_str!("main.rs.txt");

fn main() {
    if let Err(err) = run_xtask() {
        eprintln!("{err}");
    }
}

fn run_xtask() -> Result<()> {
	Xtask::try_new()?.run()
}

enum Action {
	Sol(String),
	Clip,
	Reset,
}

struct Xtask {
	lib_rs_path: PathBuf,
	main_rs_path: PathBuf,
	solved_dir: PathBuf,
}

impl Xtask {
	fn try_new() -> Result<Self> {
		let cwd = env::current_dir()?;
		let lib_rs_path = cwd.join("src").join("lib.rs");
		let main_rs_path = cwd.join("src").join("main.rs");
		let solved_dir = cwd.join("solved");

		Ok(Self {
			lib_rs_path,
			main_rs_path,
			solved_dir,
		})
	}

	fn run(&self) -> Result<()> {
		let action = parse_action();

		match action {
			Action::Sol(name) => self.sol(name)?,
			Action::Clip => self.clip()?,
			Action::Reset => self.reset()?,
		}

		Ok(())
	}

	fn sol(&self, file_name: String) -> Result<()> {
		let full_lib_code = fs::read_to_string(&self.lib_rs_path)?;

		let mut lib_code = String::new();
		let ignore = ["//", "println!", "print!"];
		let required = ["// start", "// end"];
		let mut last_line_empty = false;

		for line in full_lib_code.lines() {
			let trimed = line.trim_start();
			if !required.contains(&trimed)
				&& ignore.iter().any(|v| trimed.starts_with(v))
			{
				continue;
			}
			if !(last_line_empty && line.is_empty()) {
				lib_code.push_str(line);
				lib_code.push('\n');
			}
			last_line_empty = line.is_empty();
		}

        fs::write(self.solved_dir.join(format!("{file_name}.rs")), lib_code)?;
        fs::write(&self.lib_rs_path, LIB_TPL_CODE)?;
        fs::write(&self.main_rs_path, MAIN_TPL_CODE)?;

		Ok(())
	}

	fn clip(&self) -> Result<()> {
		use std::{
			io::Write,
			process::{Command, Stdio},
			thread,
		};

		let lib_code = fs::read_to_string(&self.lib_rs_path)?;

		let mut sol_fn_code = String::new();
		let mut flag = false;

		for line in lib_code.lines() {
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
		fs::write(&self.lib_rs_path, LIB_TPL_CODE)?;
		fs::write(&self.main_rs_path, MAIN_TPL_CODE)?;

		Ok(())
	}
}

fn parse_action() -> Action {
	let args: Vec<String> = env::args().collect();

	if args.len() == 3 && args[1] == "sol" {
		return Action::Sol(
			args[2]
				.trim()
				.replace(|ch: char| !ch.is_ascii_alphanumeric(), "_"),
		);
	}

	if args.len() == 2 && args[1] == "clip" {
		return Action::Clip;
	}

	if args.len() == 2 && args[1] == "reset" {
		return Action::Reset;
	}

	panic!("unknown action");
}
