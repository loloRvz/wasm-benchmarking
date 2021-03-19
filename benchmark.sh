#!/bin/bash

prog_name="$1"
ceil="$2"
step="$3"

#Run tests

#native
./tests/$prog_name $ceil $step > data/gcc_out.txt
#wasm
/home/lolo/bin/iwasm --dir=. tests/$prog_name.wasm $ceil $step > data/wasm_out.txt
#aot
/home/lolo/bin/iwasm --dir=. tests/$prog_name.aot $ceil $step > data/aot_out.txt
#Change permissions
chown $USER data/gcc_out.txt data/wasm_out.txt data/aot_out.txt


#Set plot description according to test being run
case $prog_name in
	pi)
		filename_str="filename_str='benchmark_graph_pi.png'"
		title_str="title_str='Benchmark: CPU-bound, Computing nth Digit of Pi'"
		xlabel_str="xlabel_str='Nth digit of pi'"
		;;
	io_write)
		filename_str="filename_str='benchmark_graph_io_write.png'"
		title_str="title_str='Benchmark: IO-bound, Writing to External File Repeatedly'"
		xlabel_str="xlabel_str='# of iterations'"
		;;
	io_access)
		filename_str="filename_str='benchmark_graph_io_access.png'"
		title_str="title_str='Benchmark: IO-bound, Accessing External File Repeatedly'"
		xlabel_str="xlabel_str='# of iterations'"
		;;
	ram)
		filename_str="filename_str='benchmark_graph_ram.png'"
		title_str="title_str='Benchmark: Memory-bound, Random Memory Access Time / Element"
		xlabel_str="xlabel_str='Size of linked list [B]'"
		;;
	*)
	
		;;
esac


#plot
gnuplot -e "${filename_str}" -e "${title_str}" -e "${xlabel_str}" plot.p








