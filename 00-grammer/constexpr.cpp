// constexpr 是将一种将部分计算由运行时转换为编译时的技术
// 确保这些被 constexpr 修饰的内容在构建时就已经准备就绪了
// 并且这些值只会计算一次
// 在 C++11 中出现，在 C++14 和 C++17 中加强
//
#include <iostream>

using namespace std;

// simple struct with static constexpr members 
// Must be static because it is constant in all structs
struct A {

  // in this case, this field must be static, because all struct 
  // are the same value, not just a single instance

  static constexpr int ID = 5;
  static constexpr char WEIGCH[] = "26.7";
  static constexpr const char* c = &WEIGCH[0];

  // we can even have compile time checks
  // 这些断言也将在程序编译时检查，检查没有通过时，编译无法通过
  static_assert(*c == '2', "Oops");
};

// we can even have a recusive function be calculate at compile time as well
constexpr int fibonacci(int i) {
  return (i <= 1) ? i : fibonacci(i - 1 ) + fibonacci(i - 2);
}


int main() {

  // let's make some constexpr variables
  //
  constexpr int i = 5;
  constexpr double d = 1.4;


  // we can declare a stuct with constexpr members
  A example;

  // let's make some constexpr functions
  //
  constexpr int f = fibonacci(10);

  // and lets print them out 

  cout << "i = " << i << endl;
  cout << "d = " << d << endl;
  cout << "result = " << f  << endl;
  cout << "struct A.ID = " << example.ID << endl;

  return 0;

}


