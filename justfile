alias t := test
alias tu := test-utils
alias p := paste

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

paste:
	cargo run -p xtask -- paste
