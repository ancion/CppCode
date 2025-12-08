// 1.fork 创建子进程
// fork返回值: (如果不根据这个返回值判断后做出不一样的处理，那么父进程和子进程将执行相同的代码)
//    > 子进程返回 0
//    > 父进程返回子进程的PID
//
// fork 出的子进程会继承父进程的资源，包括文件描述符，信号等。
//
// 使用场景: 
//
//
// 2.vfork 


#include <cstdlib>
#include <iostream>
#include <unistd.h>

using namespace std;

int main (int argc, char *argv[]) {
  

  cout << "hello work" << endl;
  int pid = fork();

  if (pid == 0)  {
    // 子进程
    cout << "child work" << endl;

  }else if (pid > 0) { 
    // 父进程(获取子进程的PID)
    cout << "parent work, get pid:  " << pid << endl;
  }

  return 0;
}
