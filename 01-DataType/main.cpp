#include <cstdio>
#include <cstring>
#include <iostream>

// 避免不同类库中的包中出现同名函数，所以使用的时候使用using声明命名空间
// 使用的时候可以省略对应的命名空间
using namespace std;


int main(void) {
  int n;
  cin >> n;
  // "\n" == endl
  cout << "Hello World!" << ++n << endl;
  return 0;
}

