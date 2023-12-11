// C++ 中的流程控制

// 顺序结构
//
// 分支结构
//
//  if () {} else {}
//  switch { case ..}
//

#include <iostream>

// if else 分支系统
//  c++ 最多支持 127 层的嵌套
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
// case 后面必须是整数或字符, 或者是结果为整数或者字符的表达式，但是不能使用变量
// default 不是必须的，可以没有, 没有 default 的时候，全部case 不匹配就不执行任何代码
// 
void switchcase() {
  int a = 10;
  switch(a) {
    // 每个分支可以比较一个值
    case 10:
      std::cout << "equals 10\n" << std::endl;
      // 默认会穿透，阻止穿透使用 break;
      break;
    case 20:
      std::cout << "equals 20\n" << std::endl;
      break;
    // 最终为 default, 可以不写
    default:
      std::cout << "default \n" << std::endl;
  }
}

// 三目表达式
void sanmu() {
  int a = 7, b = 5, c = 0;
  c = b > a ? a : b;
  std::cout << c << std::endl;
  // 三目表达式可以嵌套使用，但是，过于复杂的的嵌套，可读性很差
}

int main() {
  // 代码执行流程控制
  ifelse();

  // sammu
  sanmu();

  // case 分支
  switchcase();
}
