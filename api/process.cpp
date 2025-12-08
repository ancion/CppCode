
/**
 *
* c/C++ 进程操作
*
*/
#include <cstdlib>
#include <iostream>
#include <unistd.h>

using namespace std;

int main (int argc, char *argv[]) {

  // system 函数是用来执行外部命令的, 等待命令执行完毕，返回执行的结果之后
  // 继续执行后面的代码
  //
  int ret = system("ls -l");
  cout << "resut: " << ret << endl;


  // 替换当前进程，执行外部命令
  ret = execl("/usr/bin/ls", "./");
  cout << "resut: " << ret << endl;
  
  return 0;
}
