#include <iostream>
#include <string>

using namespace std;

template <typename T> T addr(T v) { return v; }

//
// 可变参数模板
//
// Variable number of input arguments in a template 
// "typename... Args" is a function parameter pack 
// we can use recursive calls to unpack all the arguments!
template <typename T, typename... Args> T addr(T first, Args... args) {
  // 多个参数的时候会递归调用当前函数展开，最终剩下一个参数时调用上面的 addr
  // 函数
  return first + addr(args...);
}

void func_variadic_template() {

  // We can calculate a sum variable number of integers
  int int_sum = addr(1, 2, 3, 5, 7);
  cout << "The integers is " << int_sum << endl;

  // We can calculate a sum with a variable number of folat 
  float float_sum = addr(1.5, 2.5, 3.5, 5.5, 7.5);
  cout << "The float is " << float_sum << endl;

  // Declare some string we want to combine
  string partial1 = "Hello";
  string partial2 = "World";
  string partial3 = "!!!";

  // We can concatenate a variable number of strings
  string concatenate = addr(partial1, partial2, partial3);
  cout << concatenate << endl;
}
