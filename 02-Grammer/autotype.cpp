#include <iostream>
#include <vector>

using namespace std;

// 乘法
double multiple(double a, double b) {
  return a * b;
}

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

  vector<int> int_vec;
  // 获取复杂类型
  auto iterator =  int_vec.begin();
  cout << "int_vec type is: "  << typeid(iterator).name() << endl;

}

int main (int argc, char *argv[]) {
  auto_usage();
  return 0;
}

