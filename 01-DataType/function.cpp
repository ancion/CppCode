#include <iostream>
using namespace std;

//
// cpp 中的函数
//
// ====================================================================================
// > 函数的声明必须在函数的调用之前
// ====================================================================================
// > 函数声明与定义可以分开，如果先定义，后实现可以在 main 函数前声明, main
// 函数后定义 > 如果声明和定义是在一起的，就只能写在 main 函数之前
//
//
// > 函数可以被多次声明，但是只能定义一次，否则无法被编译
// > 函数的声明与定义的函数签名必须一致, 不同的时候主要有以下几种情况 :
//    - 当返回值不一致的时候会直接无法编译，
//    - 当函数名称或者参数不一致的时候，他们就不属于同一个函数了
// -----------------------------------------------------------------------------
//
// > 函数的返回值不是必须的，当不关注返回值的时候，可以在声明的时候使用 void
//   函数体中的 return 语句可以必须书写
//
//
// -----------------------------------------------------------------------------
// > 函数之间可以相互调用，但是我们在其他函数中调用 main 函数会导致栈溢出
// > 函数调用时可以作为其他表达式的一部分，它的返回值参与表达式运算
// > 需要注意的是，返回值的类型需要匹配，否则会导致隐式转换或者编译报错
//
// -----------------------------------------------------------------------------
//
// ===================================================================================
//  函数的参数传递
// -----------------
// 调用函数的时候，调用者把数值 ==赋值== 给了函数的参数
//
//
// -----------------
// 指针类型的参数Q
//   - 可以减少函数调用时内存拷贝, 节省内存使用
//   - 可以在函数中修改实参的值
//
//

// 函数声明不需要函数体，但是必须以 ; 结尾
int add(int a, int b);

// 函数的参数不是必须的，可以是没有参数传入的
// 函数内部对于参数的修改不会影响调用时函数的实参
void arguments(int no, string str) {

  // 修改函数的参数
  str = str + ", world";
  no = no + 10;

  // 输出 str
  cout << "in f(x): " << str << " " << no << endl;
}

// 当指针类型的变量被传递到函数中，
// 在函数中修改了指针变量指向的值，这时候外部调用函数的实参也会发生变换
void make_sence(string *name, int *age) {
  cout << "name: " << *name << ", age: " << *age << endl;
  *name = "Alex";
  *age = 20;
}

int main() {
  cout << add(19, 10) << endl;

  // 函数的调用
  string hello = "hello";
  int a = 10;
  arguments(10, hello);
  // 再次查看
  cout << "callout f(x): " << hello << " " << a << endl;

  string name = "plob";
  int age = 10;
  make_sence(&name, &age);
  cout << "name: " << name << ", age: " << age << endl;
}

int add(int a, int b) { return a + b; }
