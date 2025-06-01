// 循环结构
//
// while () {};
//
// do { } while ();
//
//
#include <iostream>
#include <string>
#include <vector>

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

void newforloop() {
  // new for loop just list java and python
  for (int i : { 1, 2, 9, 3, 8, 4, 6,5}) {
    cout << i << " ";
  }
  cout << endl;

  vector<int> i_vector;

  for (unsigned i = 0; i < 6; i++) {
    int temp = rand() % 100;
    cout << temp << " ";
    i_vector.push_back(temp);
  }
  cout << endl;

  for(auto &i: i_vector) {
    // Increment each element in the vector 
    i++;
  }

  // print out the new vector
  for(unsigned i = 0; i< i_vector.size(); i++){
    cout << i_vector[i] << " ";
  }
  cout << endl;
}


void dowhile() {
  int no = 10;
  do {
    cout << no << endl;
    no--;
  } while (no > 10);
}


// 建议只在函数内部适用 goto 语法, 如果在程序中随便适用 goto 跳转
// 代码的维护性和可读性都会大幅下降
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
  newforloop();

  // do {} while()
  // 先执行一次再判断 while 条件
  dowhile();

  //
  gotoclause();

  return 0;
}
