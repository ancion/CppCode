#include <iostream>
#include <string>

// C 中使用 printf() 进行格式化输出
//
// %c  :  char
// %u  :  unsign int
// %d  :  sign int
// %e  :  指数形式的浮点数
// %g  :  把输值按照 %e 或 %f 类型中输出长度最小的方式输出
// %ld :  long 
// %hd :  short
// %f  :  float, 默认是7 位小数, 可以使用 `%.nf`  使用 n 确定保留的小数位数
// %lf :  double
// %s  :  string
// %x  :  hex (十六进制输出)
// %o  :  Oct (八进制输出)
// %p  :  pointer(打印地址)
// %x, %X : 无符号以十六进制表示的整数（常用，打印指针一般会使用）


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
