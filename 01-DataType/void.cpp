#include <iostream>
using namespace std;

// void 关键字
// ----------------------------------------------------
// void表示无类型 (主要有三个用途)
//  1. 函数的返回值
//  2. 函数的参数填 void, 表示函数不需要参数(或者让参数列表空着)
//  3. 函数的形参使用哪个 void*, 表示接受任意数据类型的指针
// ====================================================
//  注意事项:
//   > 1. 不能使用 void 声明变量，它不能代表一个真实的变量
//   > 2. 不能对 void* 指针直接解引用(需要先转换为真实的类型)
//   > 3. 把其他类型的指针赋值给 void* 不需要转换
//   > 4. 把 void* 指针赋值给其他类型的指针需要转换.

// 显示变量的十六进制地址(只关注指针本身，这里使用了void*,
// 因此可以接收任意类型的指针)
void showHexAddr(string varname, void *p) {
  cout << varname << "地址是： " << p << endl;
  // 这里假如我们要使用指针中的值，需要先转换类型才能解引用
  if (varname == "b") {
    cout << varname << "值是: " << *(char *)p << endl;
  }
}

// void
void run() {

  // 显示变量的十六进制地址
  int a;
  char b;
  cout << "a 的地址是: " << &a << endl;
  // cout 直接打印 char 类型的地址会出现一些异常不能编码的字符
  // cout << "b 的地址是: " << &b << endl;
  cout << "b 的地址是: " << (void *)&b << endl;

  // 这里 int* 和 char* 都可以传递
  showHexAddr("a", &a);
  showHexAddr("b", &a);
}

int main() { run(); }
