#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <bitset>

using namespace std;

// 编译
// g++ fs_op.cpp -o main 
// 运行
// ./main matrix1.txt matrix2.txt matrix3.txt
//
//
// matrix1.txt
//
// 1 2 3 
// 4 5 6
// 7 8 9
//
// matrix2.txt (第一行包含的是举证的规模)
// 3 
// 4 8 10
// 5 9 11
// 6 10 12
// 
// matrix3.txt 记录矩阵的乘法结果


// Different file open mode
void fs_mode() {

  // app: output is appended to the end of file
  cout << bitset<8>(ios::app) << endl;

  // ate: open a file and  seek to end of file
  cout << bitset<8>(ios::ate) << endl;

  // in: open a file for reading
  cout << bitset<8>(ios::in) << endl;

  // out: open a file for writing (also trunc)
  cout << bitset<8>(ios::out) << endl;

  // trunc: clear the file before opening it
  cout << bitset<8>(ios::trunc) << endl;

  // How t combine flags 
  cout << bitset<8>(ios::in | ios::out) << endl;

}

// print matrix
void print_matrix(int* a, int n){
  for (int i = 0; i < n * n; i++){
    cout << a[i] << " ";
  }
  cout << endl;
}

// matrix multiplication
void m_mul(int *a, int *b, int *c, int n) {
  int temp;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      temp = 0;
      for (int k = 0; k < n; k++) {
        temp += a[i * n + k] * b[k * n + j];
      }
      c[i * n + j] = temp;
    }
  }
}

int* read_file1(string name) {

  // open a file for reading
  fstream file1;
  file1.open(name, ios::in);

  int *a;
  int n = 3;
  // all int space
  size_t bytes = n * n * sizeof(int);

  // malloc space for matrix1
  //
  a = (int*) malloc(bytes);

  int temp;
  for(int i = 0; i < n; i++){ 
    for(int j = 0; j < n; j++) {
      // read data from file to memory
      file1 >> a[i * n + j];
    }
  }
  file1.close();
  print_matrix(a, n);
  return  a;

}

int* read_file2(string name) {

  // open a file for read
  fstream file2;
  file2.open(name, ios::in);

  int n;
  // read matrix size
  file2 >> n;

  int *b;
  size_t bytes = n * n * sizeof(int);
  b = (int *)malloc(bytes);

  // read matrix2 to memory
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++){
      file2 >> b[i * n + j];
    }
  }
  file2.close();
  print_matrix(b, n);
  return b;
}

void write_file3(string name, int *a, int *b) {

  // allocate memory for result and form amtrix multiplication
  int n = 3;
  size_t bytes = 36;
  int *c;
  c = (int*)malloc(bytes);
  m_mul(a, b, c, n);
  // write result
  fstream file3;
  file3.open(name, ios::out);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      file3 << c[i * n + j] << " ";
    }
    file3 << "\n";
  }

  file3.close();

}


int main(int argc, char* argv[]) {
  fs_mode();
  int *a = read_file1(argv[1]);
  int *b = read_file2(argv[2]);
  write_file3(argv[3], a, b);

  return 0;
}
