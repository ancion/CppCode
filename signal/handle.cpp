

/**
* c/C++ signal 处理
*
*/

#include <csignal>
#include <iostream>

using namespace std;


void handler(int signla) {
  cout << "signal: " << signla << endl;
}

int main (int argc, char *argv[]) {

  // 在程序中指定使用某个函数来处理对应的信号
  // 如果注册了某个信号对应的处理函数，那么该信号的默认处理行为将会被忽略
  // 
  signal(SIGCHLD, handler);

  // 忽略某种信号, 该信号将不被处理
  signal(SIGTSTP, SIG_IGN);

  return 0;
}
