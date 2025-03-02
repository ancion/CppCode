#include "../include/Shape.h"
#include "../include/mod.h"
#include "../include/Complex.h"


int main (int argc, char *argv[]) {

  // oop 测试
  oop_shape_game();

  // time 使用规则
  timeops();

  // 测试复数库的使用
  Complex c(1, 2);
  Complex a(2, 2);
  cout << c + a << endl;

  return 0;
}
