# WebAssembly Benchmarking

## Description

This repo tests the performance of WebAssembly to native C algorithms.


List of available tests:

* ```pi``` :            CPU-bound, Computes the n-th digit of pi.
* ```io_write``` :      IO-bound, Writing to an external file repeatedly
* ```io_access``` :     IO-bound, Accesses an external file repeatedly
* ```ram``` :           Memory-bound, Accesses an external file repeatedly


## Instructions
###Build the executables:

```
sudo bash ./build.sh <program_name>
```

###Run the benchmark:

```
sudo bash ./benchmark <program_name>
```
###Example

The following example is a CPU-bound benchmark test, which computes the n-digit of pi:

```
sudo bash ./build.sh pi
sudo bash ./benchmark.sh pi
```

###Results
![alt text](https://github.com/loloRvz/wasm-benchmarking/blob/main/benchmark_graph_pi.png)
![alt text](https://github.com/loloRvz/wasm-benchmarking/blob/main/benchmark_graph_io_access.png)
![alt text](https://github.com/loloRvz/wasm-benchmarking/blob/main/benchmark_graph_io_write.png)
![alt text](https://github.com/loloRvz/wasm-benchmarking/blob/main/benchmark_graph_ram.png)



