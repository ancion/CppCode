#include <cstdlib>
#include <cstring>
#include <vector>
#include <benchmark/benchmark.h>

using namespace std;

// --------------------------------------------------
// g++ read_bench.cpp -lbenchmark -lpthread -O3 -mavx2 -o read_bench
// --------------------------------------------------
static void readBench(benchmark::State &s) {
  // Get the size from the input
  int dim = s.range(0);

  // Allocate and initialize
  float *matrix = new float[dim * dim];
  for(int i = 0; i < dim * dim; i++) {
    matrix[i] = rand() % 100;
  }

  float sink = 0;

  while(s.KeepRunning()){
    for(int i = 0; i < dim * dim; i++){
      sink = matrix[i];
    }
  }
  benchmark::DoNotOptimize(sink);

  // Set the items processed
  s.SetItemsProcessed(s.iterations() * dim * dim);
  // Set bytes processed
  s.SetBytesProcessed(s.iterations() * dim * dim * sizeof(float));

  // free memory
  delete[] matrix;

}

BENCHMARK(readBench)->DenseRange(8, 10);

BENCHMARK_MAIN();
