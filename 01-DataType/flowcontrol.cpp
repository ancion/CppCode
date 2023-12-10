// C++ 中的流程控制

// 顺序结构
//
// 分支结构
//
//  if () {} else {}
//  switch { case ..}
//
// 循环结构
//
// while () {};
//
// do { } while ();
//
//
//

#include <iostream>

// if else 分支系统
void ifelse() {

  int a = 20, b = 10;

  // if 后的表达式必须要写括号,
  // 表达式可以是值，运算表达式, 逻辑表达式.
  // 赋值表示式(赋值表达式的结果为等号右边的值) if (a = b)
  // 如果写成 if (a = b) 就是直接使用 b 的值来判断了
  //
  if (a == b) {
    // 如果分支代码只有一行的时候，可以省略 {}
    std::cout << (a == b) << std::endl;
    // 如果分支没有代码，则必须要写 {}
    // 如果有多行，也是必须要写的，如果没有写则默认只会包含分支下的第一行代码，
    // 其他部分会被看作分支外的代码被执行
  }

  // if 语句可以没有 else
  // else {}
}


// switch 分支
void switchcase() {


}

int main() {
  // 代码执行流程控制
  ifelse();

  // case 分支
  switchcase();

}
