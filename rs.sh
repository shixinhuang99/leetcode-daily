#!/bin/bash

set -e

readonly rs="cargo run -p rs"

$rs >./output.txt
