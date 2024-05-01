#!/bin/bash
set -eux

# unknown problem...
/bin/cp -rf -p calc.s calc.S

gcc -march=armv8-a -O3 -g -o rr common.S calc.S ts.c
cat calc.S
./rr
