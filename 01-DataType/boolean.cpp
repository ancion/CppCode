#include <iostream>

using namespace std;

void boolean() {
  // cpp 中的布尔值，只有两个值，true 和 false
  // C中是没有布尔值的，只有0 和 1
  // cpp 在进行逻辑判断的时候，会将一切非零数字转换为true，0转换为false
  int a = 1;
  int b = 0;
  int c = -1;
  bool flag = true;
  bool flog = false;

  cout << a << endl;
  cout << b << endl;
  cout << c << endl;
  // 在输出的时候。true -> 1 ， false -> 0
  cout << flag << endl;
  cout << flog << endl;

}
