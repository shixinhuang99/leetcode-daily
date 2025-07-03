alias t := test
alias tu := test-utils
alias c := clip
alias r := reset

default:
	just --list --unsorted

fmt:
	cargo fmt --all
	taplo fmt
	node --run fmt

lint: fmt
	cargo clippy --all-targets --all-features

test:
	cargo test --lib

test-utils:
	cargo test --lib -F test_utils

sol lang num:
	cargo xtask sol {{lang}} {{num}}
	git add .
	git commit -m "{{num}}"

clip lang:
	cargo xtask clip {{lang}}

reset:
	cargo xtask reset
