// This program implements a simple benchmark for matrix vector
// multiplcation to show a basic optimization process

#include <benchmark/benchmark.h>
#include <cstdlib>

using namespace std;

void matrix_vector(float *m, float *v, float *r, int dim) {
  for (int i = 0; i < dim; i++) {
    r[i] = 0;
    for (int j = 0; j < dim; j++) {
      r[i] += m[i * dim + j] * v[j];
    }
  }
}

// --------------------------------------------------------------
// g++ mv_bench.cpp -lbenchmark -lpthread -O3 -mavx2 -o mv_bench
// ---------------------------------------------------------------


static void mvBench(benchmark::State &s) {
  // Get the size from  input
  int dim = 1 << s.range(0);

  // Allocate and intialize 
  float *matrix = new float[dim * dim];
  float *vec = new float[dim];
  float *res = new float[dim];

  // Initialize the alloacated space
  for (int i = 0; i < dim; i++) {
    vec[i] = rand() % 100;
    res[i] = 0;
    for (int j = 0; j < dim; j++) {
      matrix[i * dim + j]= random() % 100;
    } 
  }

  // Run matrix vector product in a loop
  while(s.KeepRunning()) {
    matrix_vector(matrix, vec, res, dim);
  }

  // free memory
  delete[] matrix;
  delete[] vec;
  delete[] res;

  // Set the items processed
  s.SetItemsProcessed(s.iterations() * dim * dim);

  // set bytes processed
  s.SetBytesProcessed(s.iterations() * dim * dim * sizeof(float));
}
// Register the benchmark
BENCHMARK(mvBench)->DenseRange(8, 10); 

BENCHMARK_MAIN();

