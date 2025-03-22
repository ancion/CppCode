#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// c++ 中的 lambda
// Why lambdas? 
// Concise way of defining function object passed to STL algorithms
// Can create a function with naming it


struct building {
  string name;
  int height;
};

void lambda_usage() {
  // sort custom objects
  vector<building> buildings {
    building{ "Office", 200 },
    building{ "Bank", 100 },
    building{ "Skyscraper", 300 },
    building{ "School", 100 },
    building{ "Hospital", 200 },
  };

  // Print out the unsorted list of objects
  cout << "pre-sort" << endl;
  for(auto &s: buildings) {
    cout << "Building name: " << s.name << " Building height: " << s.height << endl;
  }
  // sort rule
  auto sort_rules =  [](const building &b1, const building &b2) {
    return b1.height < b2.height;
  };

  // sort by height
  sort(buildings.begin(), buildings.end(), sort_rules);

  cout << "port-sort" << endl;
  for(auto &s: buildings) {
    cout << "Building name: " << s.name << " Building height: " << s.height << endl;
  }
}

int main() {

  // Mininal lambda that take no parameters, and just 
  // prints something
  [] {
    cout << "Hello world!" << endl;
  }();
  cout << endl;


  // We can also assign lambdas to a variable 
  auto print_lambda = [] {
    cout << "Hello world!" << endl;
  };
  // Call it like a funciton
  print_lambda();
  cout << endl;

  // we can pass parameters to lambda
  auto parameter_lambda = [] (const string &s) -> double {
    cout << s << endl;
    return 1.22;
  };
  // call it like function wiht a parameter and return value 
  const string some_string("Some_constant_string");
  double some_num = parameter_lambda(some_string);
  cout << some_num << endl;
  cout << endl;


  auto a = 1, b = 2, c = 3;

  // []  不捕获外部变脸，可通过传递参数的方式
  // [=] 表示捕获所有外部变量,但是这些变量是只读的
  // [&] 表示捕获所有外部变量,但是这些变量是可读可写
  // [=,&b] 逗号分割的多个表达式，则是逻辑上的并且关系
  //       表示捕获所有外部变量, 但是只有 b 是可读可写的
  auto capture_lambda = [&](int &c, int &b) {
    // 内部直接捕获并修改了外部作用域中的变量
    // 因为捕获了所有外部可用变量的引用
    // 如果使用 = 捕获则无法修改是只读的
    ++a;
    return a + b;
  };
  auto result = capture_lambda(c, b);
  cout << "a: " << a << ", b: " << b << ", result: " << result << endl;

  lambda_usage();

}


