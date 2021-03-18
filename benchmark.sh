#!/bin/bash

prog_name="$1"
ceil="$2"
step="$3"

#Run tests

#native
./tests/$prog_name $ceil $step > gcc_out.txt
#wasm
/home/lolo/bin/iwasm tests/$prog_name.wasm $ceil $step > wasm_out.txt
#aot
/home/lolo/bin/iwasm tests/$prog_name.aot $ceil $step > aot_out.txt
#Change permissions
chown $USER gcc_out.txt wasm_out.txt aot_out.txt



gnuplot plot.p








