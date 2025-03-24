//
// This program show off high resolution clocks in the c++11 standard

#include <iostream>
#include <chrono>
#include <stdlib.h>

using namespace std;

// Helper function for getting the current time for profillig
chrono::high_resolution_clock::time_point get_time() {
  return chrono::high_resolution_clock::now();
}

//
void time_chrono() {

  // Vector size
  int N = 1 << 25;


  // Allocate 3 arrays
  int *a = new int[N];
  int *b = new int[N];
  int *c = new int[N];
 
  // initialize the vectors
  for(int i = 0; i < N; i++) {
    a[i] = rand() % 100 + 1;
    b[i] = rand() % 100 + 1;
  }

  // Perform and profile vector addition
  auto begin = get_time();
  for(int i = 0; i < N; i++) {
    c[i] = a[i] + b[i];
  }
  auto end = get_time();

  // 默认是秒
  auto span_s = chrono::duration_cast<chrono::duration<double>>(end - begin);
  // 可以通过泛型参数指定为毫秒
  auto span_ms = chrono::duration_cast<chrono::duration<double, milli>>(end - begin);
  // 可以使用泛型参数指定为纳秒
  auto span_ns = chrono::duration_cast<chrono::duration<double, nano>>(end - begin);

  cout << "Elapsed time: " << span_s <<  "s" << endl;

  // Free memory
  delete [] a;
  delete [] b;
  delete [] c;

}


