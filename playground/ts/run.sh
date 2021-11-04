#!/bin/bash

set -e

run="./node_modules/.bin/ts-node ./test.ts"

if [[ $1 && $1 = "-f" ]]
then
  $run > ./test.txt
else
  $run
fi
