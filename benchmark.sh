#!/bin/bash

prog_name="$1"
ceil="$2"
step="$3"

#Run tests

#native
./tests/$prog_name $ceil $step > data/gcc_out.txt
#wasm
/home/lolo/bin/iwasm tests/$prog_name.wasm $ceil $step > data/wasm_out.txt
#aot
/home/lolo/bin/iwasm tests/$prog_name.aot $ceil $step > data/aot_out.txt
#Change permissions
chown $USER data/gcc_out.txt data/wasm_out.txt data/aot_out.txt



gnuplot plot.p








