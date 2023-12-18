//
// c++ 中的类型别名
// -------------------------------------------------
//  语法：typedef 数据类型 别名
// -------------------------------------------------
//  > 为名称复杂的类型创建别名，方便书写和记忆
//  > 创建与平台无关的数据类型，提高程序的兼容性
//
//

#include <iostream>

using namespace std;

// 统一的数据类型别名，屏蔽平台细节
// windows 中short 是2字节，int 是4字节，long 也是4字节，long long 是8字节
// Linux   中short 是2字节，int 是4字节，long 也是8字节，long long 是8字节
// 以后在源代码中使用这些别名，不使用原始的类型(这些别名定义在头文件中)
typedef short i16;
typedef int i32;
typedef long long i64;

int main() {

  // 使用类型别名
  i64 x = 23453535;
  cout << "sizeof(i64)" << x << endl;

  //
}
