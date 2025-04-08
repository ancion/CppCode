#include <iostream>
#include <cstring>
#include <vector>
#include <benchmark/benchmark.h>

using namespace std;

// This program contains a simple benchmark for tesing 
// the how the SSO 
// help performance on small string


static void stringBench(benchmark::State &s) {

  // Get the number of characters for our string
  int string_len = s.range(0);

  //Vector for holding the string
  vector<string> v;
  v.resize(10000);

  // Now let's emplace back a ton of string
  while (s.KeepRunning()) {
    for (int i = 0; i< 10000; i++) {
      // Create the string of a specified size
      string str(string_len, 'a');
      v.push_back(str);
    }
  }
}

// Register the benchmark and specify a range of string values
BENCHMARK(stringBench) -> DenseRange(0, 32);

// Benchmark main function
BENCHMARK_MAIN();
