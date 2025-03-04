#include <iostream>

using namespace std;

// cpp 中的函数指针
// ========================================================
// > 函数的二进制代码存放在内存四区中的代码段, 函数的地址
//   就是它在内存中的开始地址, 如果把函数的地址作为参数
//   就可以在函数中灵活的调用地址指向的函数.
// ---------------
// > 使用函数指针的三个步骤
//  1. 声明函数指针；
//  2. 让函数指针指向函数的地址
//  3. 通过函数指针调用函数
//
//


// 申明函数指针
// 声明普通指针的时候必须提供指针的类型，同样，申明函数指针时，必须提供函数类型
// 函数的类型是指(函数的返回值和参数列表<函数名和形参名不是>)

void declare_func_point() {

  // 相同类型函数
  int func1(int a, string str);
  int func2(int no, string message);
  int func3(int id, string info);

  // 对应的函数指针的声明是
  // 主要重点是返回值和参数的类型，形参名可以不写，没有实际意义
  // 中间的就是指针的具体名称(整体是函数申明, 不可分割)
  int (*fpa)(int, string);

  // 另一个函数
  int (*f)(string, int);

  // 返回值不同, 与前三种不同类型
  bool func4(int id, string info);
  // 对应的函数声明
  bool (* fpb) (int a, string b);

  // 参数数不同，与前面不同
  int func5(int id);
  int (* fpc) (int);
}


void display(int no, string msg){
  cout << "hello" << no << ", you are my super start, " << msg << endl;
}

void funcpointcall () {

  int no = 8989;
  string msg = "I love you";
  // 函数调用
  display(no, msg);

  // 我们怎样用函数指针来完成函数的调用呢
  // 首先需要有函数指针的声明
  void (*show) (int, string);
  // 函数指针赋值(C++ 中函数名就是函数指针)
  show = display;
  // 调用函数 C++ 的方式
  show(no, msg);
  // C 语言的调用方式
  (*show)(no, msg);

}


// 函数指针作为其他函数的参数
void custom(int no) {
  cout << "make superise: " << no << endl;
}

void flow(void (*c)(int), int no) {
  cout << "start, open music" << endl; // 函数调用之前
  c(no); // 个性化操作
  cout << "end, start lauch" << endl;  // 函数调用之后
}

int main(){
  // 申明函数指针
  declare_func_point();

  // 使用函数指针调用函数
  funcpointcall()

  // 将函数作为参数进行调用
  flow(custom, 8990);
}

