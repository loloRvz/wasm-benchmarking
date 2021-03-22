# WebAssembly Benchmarking

## Description

This repo compares the performance of native C compiled programs to their WebAssembly binaries running in WAMR.


List of available tests:

* ```pi``` :            CPU-bound, computes the n-th digit of pi.
* ```io_write``` :      IO-bound, writing to an external file repeatedly.
* ```io_access``` :     IO-bound, accesses an external file repeatedly.
* ```ram``` :           Memory-bound, iterates through a linked list of variable length.


## Instructions

### Prerequisites

* [WebAssembly Micro Runtime](https://github.com/bytecodealliance/wasm-micro-runtime) with wamrc and iwasm in your path and wasi-sdk in /opt
* clang: ```sudo apt install clang```

### Build the executables:

```
sudo bash ./build.sh <program_name>
```

### Run the benchmark:

```
sudo bash ./benchmark <program_name>
```
### Example

The following example is a CPU-bound benchmark test, which computes the n-digit of pi:

```
sudo bash ./build.sh pi
sudo bash ./benchmark.sh pi
```

## Results
### pi
![alt text](https://github.com/loloRvz/wasm-benchmarking/blob/main/benchmark_graph_pi.png)
### io_write
![alt text](https://github.com/loloRvz/wasm-benchmarking/blob/main/benchmark_graph_io_access.png)
### io_access
![alt text](https://github.com/loloRvz/wasm-benchmarking/blob/main/benchmark_graph_io_write.png)
### ram
![alt text](https://github.com/loloRvz/wasm-benchmarking/blob/main/benchmark_graph_ram.png)



