#include <iostream>
#include <string>

// iostream 文件中定义的 std 包中规定了控制台的标准输入输出
//
// <<  表示输出的方向，可以像管道一样，多次拼接
//
// std::cout : console out
// std::cin  : console in
// std::endl : endline 就是 `\n` 是相同的含义

using namespace std;


int main() {

  // 如果输入的数据与变量的类型不匹配，可能会导致代码运行的行为的不确定性.
  string name;
  cout << "请输入姓名: ";
  cin >> name;

  int age;
  cout << "请输入年龄: ";
  cin >> age;


  std::cout << "name: "
            << name
            << ", age: " << age << std::endl;
}
