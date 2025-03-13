#include "../include/cppmod.h"
#include "../include/Shape.h"
#include "../include/Complex.h"

void test_oop() {

  // oop 测试
  oop_shape_game();

  // 测试复数库的使用
  Complex c(1, 2);
  Complex a(2, 2);
  cout << c + a << endl;

  // class inherite
  oop_feature();

}
