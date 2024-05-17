alias t := test
alias tu := test-utils
alias c := clip
alias r := reset

default:
	just --list --unsorted

fmt:
	cargo fmt --all
	taplo fmt

lint: fmt
	cargo clippy --all-targets --all-features

test:
	cargo test --lib

test-utils:
	cargo test --lib -F test_utils

sol num:
	cargo run -p xtask -- sol {{num}}
	git add solved/{{num}}.rs
	git commit -m "{{num}}"

clip:
	cargo run -p xtask -- clip

reset:
	cargo run -p xtask -- reset
