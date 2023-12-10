// 循环结构
//
// while () {};
//
// do { } while ();
//
//
#include <iostream>
#include <string>

using namespace std;

// while
void whileloop() {

  // 超女的编号
  int no = 1;

  // 死循环
  // while (true) {}

  // 循环体只有一行的时候可以省略大括号
  while (no < 10) {
    no++;
    if (no == 5) {
      // continue 终止当循环
      continue;
    }

    if (no == 10) {
      // break 终止循环
      break;
    }
    cout << no << endl;
  }
}

// for 循环
void forloop() {
  // for 中的三个表达式都可以为空，for(;;){} 等同于  while(true){}
  for (int i = 0; i < 10; i++) {
    cout << "i = " << i << endl;
  }
}

void dowhile() {
  int no = 10;
  do {
    cout << no << endl;
    no--;
  } while (no > 10);
}


void gotoclause() {

  cout << "start" << endl;
  cout << "game" << endl;

  // 直接跳转到某个语句标识的位置
  goto start;
  cout << "over" << endl;

// 语句标志, 顶格写，名称 + :
//
start:
  cout << "hello" << endl;
  cout << "world" << endl;
}

int main() {
  // while 循环
  whileloop();

  // for 循环
  forloop();

  // do {} while()
  // 先执行一次再判断 while 条件
  dowhile();

  //
  gotoclause();

  return 0;
}
