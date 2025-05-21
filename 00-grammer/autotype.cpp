#include <functional>
#include <iostream>
#include <type_traits>
#include <vector>

using namespace std;

// 乘法
double multiple(double a, double b) { return a * b; }

void auto_usage() {

  // 测试 auto 的使用
  auto x = 10;
  cout << "x type is: " << typeid(x).name() << endl;

  // 获取 double 类型
  auto y = multiple(1.3, 3.4);
  cout << "y type is: " << typeid(y).name() << endl;

  auto c = 'c';
  cout << "c type is: " << typeid(c).name() << endl;

  auto arr = new int[10];
  cout << "arr type is: " << typeid(arr).name() << endl;

  auto z = "word";
  cout << "z type is: " << typeid(z).name() << endl;

  // 获取复杂类型
  vector<int> v = {1, 2, 3};

  // vector<int>::iterator v1 = v.begin();
  auto v1 = v.begin();
  for (; v1 != v.end(); ++v1) {
    cout << *v1 << " ";
  }
  cout << endl;
  cout << "vec iterator type is: " << typeid(v1).name() << endl;
}

void declare_type() {

  int a = 1;
  double b = 2.12;

  // 自定推导类型
  decltype(a + b) c = a + 3.14;
  // 自定推导类型
  auto d = a + b;
}

void mix_use() {
  // 定义 lambda 函数
  auto minus_func = [](int a, int b) { return a - b; };

  // 使用decltype 来获取对应的函数的类型作为泛型参数
  vector<function<decltype(multiple)>> funcVec = {multiple, minus_func};

  auto m = funcVec[0](1, 3);
  auto n = funcVec[1](2, 4);

  cout << "m: " << m << endl;
  cout << "n: " << n << endl;
}

//
// 自动推导复杂类型的返回值(返回值类型后置)
//
auto sum(int a, double b) -> decltype(a + b) { return a + b; }

//
// 函数模板中 (C++14 之后，后置返回类型可以省略)
//
template <typename T, typename U> auto get_sum(T a, U b) -> decltype(a + b) {
  return a + b;
}

//
// 修饰左值和右值的区别
//
struct Object {
  const int a;
  double b;
  Object(): a(1), b(2) {}
};

void left_right_decl() {

  const Object obj;

  auto check1 = is_same<decltype(obj), const Object>::value;
  auto check2 = is_same<decltype((obj)), const Object&>::value;
  cout << "obj type: " << check1 << ", (obj) type: " << check2 << endl;
  
  auto check3 = is_same<decltype(obj.a), const int>::value;
  auto check4 = is_same<decltype((obj.a)), const int&>::value;
  cout << "obj.a type: " << check3 << ", (obj.a) type: " << check4 << endl;
  
  auto check5 = is_same<decltype(obj.b), double>::value;
  // (obj.b) 返回的是 const double&, 收到 obj 对象是 const 影响
  auto check6 = is_same<decltype((obj.b)), const double&>::value;
  cout << "obj.b type: " << check5 << ", (obj.b) type: " << check6 << endl;

}

int main(int argc, char *argv[]) {
  auto_usage();

  declare_type();

  mix_use();

  left_right_decl();

  return 0;
}
