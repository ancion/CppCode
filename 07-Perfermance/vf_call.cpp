#include <algorithm>
#include <vector>
#include <random>
#include <iterator>
#include <benchmark/benchmark.h>

using namespace std;


struct Mammal {

  virtual float getSomeNumber() {
    return 1.0f;
  }
};

struct Dog: Mammal {
  float getSomeNumber() const noexcept {
    return 2.0f;
  }
};

struct Cat: Mammal {
  float getSomeNumber() const noexcept {
    return 3.0f;
  }
};

static void vf_sorted(benchmark::State &s) {
  // Create a vector to store mammals
  vector<Mammal*> zoo;

  // Use fill_n to insert many instances into the vector
  fill_n(back_inserter(zoo), 10000, new Mammal);
  fill_n(back_inserter(zoo), 10000, new Dog);
  fill_n(back_inserter(zoo), 10000, new Cat);

  // Acculate a sum here
  float sum = 0;
  // profile here
  while(s.KeepRunning()) {
    //VF calls here are easy to predict because all instances of each type
    // are sequential in the vector
    for (auto* animal: zoo) {
      sum += animal -> getSomeNumber();
    }
  }
}

BENCHMARK(vf_sorted);

static void vf_unsorted(benchmark::State &s) {
  // Create a vector to store mammals
  vector<Mammal*> zoo;

  // Use fill_n to insert many instances into the vector
  fill_n(back_inserter(zoo), 10000, new Mammal);
  fill_n(back_inserter(zoo), 10000, new Dog);
  fill_n(back_inserter(zoo), 10000, new Cat);

  // Now shuffle the vector
  random_device rng;
  mt19937 urng(rng());
  shuffle(zoo.begin(), zoo.end(), urng);

  // Allocate a sum vector
  float sum = 0;

  // profile here
  while(s.KeepRunning()) {
    // VF Calls  here are ~random, so the branch predicter will have 
    // some trouble
    for(auto* animal: zoo) {
      sum += animal -> getSomeNumber();
    }
  }
}

// Register the benchmark
BENCHMARK(vf_unsorted);

BENCHMARK_MAIN();
