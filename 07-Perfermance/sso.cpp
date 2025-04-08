// short string optimization 
//

#include <cstdlib>
#include <iostream>

using namespace std;

// overload new operator to track heap allocation
void* operator new(size_t n) {
  cout << "Allocation: " << n << endl;
  malloc(n);
}


void usage_short_string() {

  // First, let's see how big a string is
  size_t string_size = sizeof(string);
  cout << "Size of string " << string_size << endl;

  // 观察内存分配的情况, 栈上最多存储15 个字节
  // 在此之后的每一存储都要重新分配
  // we can only store 15 character in situ 
  // inside of the string on the stack
  // so that means anything after this. we have to make heap 
  // aollocation 
  for (size_t i = 0; i < string_size; i++){
    string s(i, 'x');
    cout << i << " : " << s << endl;
  }
}

int main() {
  usage_short_string();
}
