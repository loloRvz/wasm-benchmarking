#Lil script for plotting with gnuplot

set terminal png size 1000,700

set output filename_str

set title title_str
set xlabel xlabel_str
set ylabel ylabel_str

set key left box

plot "data/out_gcc.txt" with lines title "gcc native", \
	 "data/out_clang.txt" with lines title "clang native", \
     "data/out_wasm.txt" with lines title ".wasm wamr", \
     "data/out_aot.txt" with lines title ".aot wamr"
