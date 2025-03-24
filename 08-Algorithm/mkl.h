
#include <chrono>

// intel  mkl 对自己架构的优化
//
template<class T>
void simple_gemm(T *a, T *b, T *c, int m, int n, int k, T alpha, T beta) {
  // temp  variable for accumulating the reuslts
  T temp;
  // For each row...
  for (int i = 0; i < m; i++) {
    // for each column ...
    for (int j = 0; j < n; j++) {
      // Reset partiual result
      temp = 0;
      //Calculate 1 element of the final matrix
      for (int l = 0; l < k; l++) {
        temp += alpha * a[i * k + l] * b[l * n + j];
      }
      // Write it back to the reseult matrix
      c[i * n + j] = beta * c[i * n + j] + temp;
    }
  }
}

// Initializes a matrix of dimension " m x n"
// Arguments
// a     =  Matrix 
// m     =  Number of rows
// n     =  Number of columns
// value =  Value to initialize the matrix with
template <class T>
void init_matrix(T *a, int m, int n, T value = 1) {
  for (int i = 0; i < m * n ; i++) {
    if (value == 1) {
      a[i] = (T)(rand() % 100);
    }else {
      a[i] = 0;
    }
  }
}

// Helper functon to getting the current time for progilling
auto get_time() {
  return std::chrono::high_resolution_clock::now();
}
