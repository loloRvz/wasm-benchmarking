# WebAssembly Benchmarking

## Description

This repo tests the performance of WebAssembly to native C algorithms.

## Building Executables

```
sudo bash ./build.sh <program_name>
```

List of available programs:

* ```pi``` : Computes the n-th digit of pi. For CPU-bound benchmarks.

## Running Benchmark

```
sudo bash ./benchmark <program_name> <iteration_ceiling> <iteration_step>
```

## Example

The following example is a CPU-bound benchmark test, which computes the n-digit of pi:

```
sudo bash ./build.sh pi
sudo bash ./benchmark.sh pi 100 1
```

Which produces the following output:

![alt text](https://github.com/loloRvz/wasm-benchmarking/blob/main/benchmark_graph.png)

