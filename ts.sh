#!/bin/bash

set -e

run="./playground/ts/node_modules/.bin/ts-node ./playground/ts/test.ts"

if [[ $1 && $1 = "-f" ]]
then
  $run > ./playground/ts/test.txt
else
  $run
fi
