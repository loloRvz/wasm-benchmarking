#!/bin/bash

prog_name="$1"

#Building executables

#gcc
gcc -o tests/$prog_name tests/$prog_name.c -lm
#wasm
/opt/wasi-sdk/bin/clang -O3 -o tests/$prog_name.wasm tests/$prog_name.c
#aot
/home/lolo/bin/wamrc -o tests/$prog_name.aot tests/$prog_name.wasm

#Change permissions
chown lolo tests/$prog_name tests/$prog_name.wasm tests/$prog_name.aot









