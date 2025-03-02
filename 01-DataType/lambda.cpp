#include <iostream>
// c++ 中的 lambda 
//
void lambda_usage() {
  using namespace std;

  auto a = 1, b= 2, c = 3;

  // 定义一个可以捕获外部变量的 lambda
  // 当我们不已引用的方式来定义 lambda, 则不能使用外部变量
  
    auto _swap = [&](int& a, int&b ) -> void {
    // 不引用外部变量
    // auto _swap = [](int& a, int&b ) -> void {
    // 直接使用赋值的方式来定义
    // auto _swap = [=](int& a, int&b ) -> void {
    auto tmp = a;
    a = b;
    b = tmp;
    cout << c << endl;
  };
  _swap(a, b);
}


