use std::{env, fs};

fn main() {
    let action = parse_args();

    match action {
        Action::Sol(num) => sol(num),
        Action::Paste => paste(),
    }
}

enum Action {
    Sol(i32),
    Paste,
}

fn parse_args() -> Action {
    let args: Vec<String> = env::args().collect();

    if args.len() == 3 && args[1] == "sol" {
        return Action::Sol(
            args[2].parse::<i32>().expect("invalid problem number"),
        );
    }

    if args.len() == 2 && args[1] == "paste" {
        return Action::Paste;
    }

    panic!("unknown action");
}

const LIB_TPL: &str = include_str!("lib.rs.txt");

const MAIN_TPL: &str = include_str!("main.rs.txt");

fn sol(num: i32) {
    let cwd = env::current_dir().expect("invalid cwd");
    let lib_rs_path = cwd.join("src").join("lib.rs");
    let main_rs_path = cwd.join("src").join("main.rs");
    let solved_dir = cwd.join("solved");
    let lib_code =
        fs::read_to_string(&lib_rs_path).expect("read lib.rs failed");

    fs::write(solved_dir.join(format!("{}.rs", num)), lib_code)
        .expect("write solved file failed");

    fs::write(lib_rs_path, LIB_TPL).expect("reset lib.rs failed");

    fs::write(main_rs_path, MAIN_TPL).expect("reset main.rs failed");
}

fn paste() {
    use std::{
        io::Write,
        process::{Command, Stdio},
        thread,
    };

    let cwd = env::current_dir().expect("invalid cwd");
    let lib_rs_path = cwd.join("src").join("lib.rs");
    let lib_code = fs::read_to_string(lib_rs_path).expect("read lib.rs failed");

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

    #[cfg(target_os = "macos")]
    {
        let mut pbcopy = Command::new("pbcopy")
            .stdin(Stdio::piped())
            .spawn()
            .expect("failed to start pbcopy");

        let mut stdin = pbcopy.stdin.take().expect("failed to open stdin");

        thread::spawn(move || {
            stdin
                .write_all(sol_fn_code.as_bytes())
                .expect("failed to wirte to stdin");
        });

        pbcopy.wait().expect("pbcopy wasn't running");
    }
}
