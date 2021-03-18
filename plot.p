#Lil script for plotting with gnuplot

set terminal png size 1000,700

set output 'pi_benchmark.png'

set title "Benchmark test: Runtime computing n-th digit of pi"
set xlabel "N-digit of pi"
set ylabel "Computing time [ms]"

set key left box

plot "data/gcc_out.txt" with lines title "Native", \
     "data/wasm_out.txt" with lines title ".wasm", \
     "data/aot_out.txt" with lines title ".aot"
