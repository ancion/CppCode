#include <iostream>

using namespace std;

// C++ 种 bool 类型
// C 中是没有布尔值的，只有0 (false) 和 非 0 为（true）
// C++ 为了提高代码的可读性, 新增的 bool 类型，占用一个字节, 只有 true 和 false
//     两个值其本质就是占用一个字节的整数，只有两个取值 0,1
//     (在程序书写的时候可以使用 true, false, 编译器会自动解释为 1 和 0)

void boolean() {
  // cpp 在进行逻辑判断的时候，会将一切非零数字转换为true，0 转换为false
  int a = 1;
  int b = 0;
  int c = -1;
  bool flag = true;
  bool flog = false;

  cout << a << endl;
  cout << b << endl;
  cout << c << endl;

  // 在使用 cin, cout 输入，输出的时候, 会直接以 true -> 1 ， false -> 0
  // 方式输出
  cout << flag << endl;
  cout << flog << endl;
}

// 我们直接获取 bool 类型值的内存指针，并修改值
// 从而验证 bool 类型的底层就是使用的 unsigned char 来存储的
// true 和 false 只用 C++ 在语法上的处理
//
void ptr_bool() {

  bool b = false;
  cout << "b = " << b << endl;
  // 获取b (bool) 指针地址赋值给 c
  char *c = (char *)&b;

  *c = (char)255;
  // 再次输出 b
  cout << "b = " << b << endl;
}

int main() {

  // boolean
  boolean();

  // 通过指针修改 bool 变量值,验证底层使用无符号1字节整数存储的事实
  ptr_bool();

  return 0;
}
