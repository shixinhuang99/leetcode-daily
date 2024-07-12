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
	cargo xtask sol {{num}}
	git add .
	git commit -m "{{num}}"

clip:
	cargo xtask clip

reset:
	cargo xtask reset
