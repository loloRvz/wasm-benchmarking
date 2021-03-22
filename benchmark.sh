#!/bin/bash

prog_name="$1"

##Run tests

#native gcc
./tests/$prog_name \
	> data/out_gcc.txt
	
#native clang
./tests/$prog_name.x \
	> data/out_clang.txt
	
#wasm
/home/lolo/bin/iwasm --dir=. tests/$prog_name.wasm \
	> data/out_wasm.txt
	
#aot
/home/lolo/bin/iwasm --dir=. tests/$prog_name.aot \
	> data/out_aot.txt
	
	
#Change permissions
chown $USER data/out_gcc.txt \
			data/out_clang.txt \
			data/out_wasm.txt \
			data/out_aot.txt


#Plot according to test being run
case $prog_name in
	pi)
		gnuplot -e "filename_str = 'benchmark_graph_pi.png'" \
				-e "title_str    = 'Benchmark: CPU-bound, Computing nth Digit of Pi'" \
				-e "xlabel_str   = 'Nth digit of pi'" \
				-e "ylabel_str   = 'Computing time [ms]'" \
				plot.p
		;;
		
	io_write)
		gnuplot -e "filename_str = 'benchmark_graph_io_write.png'" \
				-e "title_str    = 'Benchmark: IO-bound, Writing to External File Repeatedly'" \
				-e "xlabel_str   = '# of iterations'" \
				-e "ylabel_str   = 'Computing time [ms]'" \
				plot.p
		;;
		
	io_access)
		gnuplot -e "filename_str = 'benchmark_graph_io_access.png'" \
				-e "title_str    = 'Benchmark: IO-bound, Accessing External File Repeatedly'" \
				-e "xlabel_str   = '# of iterations'" \
				-e "ylabel_str   = 'Computing time [ms]'" \
				plot.p
		;;
		
	ram)
		gnuplot -e "filename_str = 'benchmark_graph_ram.png'" \
				-e "title_str    = 'Benchmark: Memory-bound, Random Memory Access Time / Element" \
				-e "xlabel_str   = 'Size of linked list [Bytes]'" \
				-e "ylabel_str   = 'Time/element [ns]'" \
				plot.p
		;;
esac










