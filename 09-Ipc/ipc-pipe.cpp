#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <cstring>

using namespace std;

// 基于管道的父子进程间通信
//
int main() {
  int fd[2];
  pipe(fd);

  if (fork() == 0) { // make child process
    close(fd[0]);  // close read end
    const char* msg = "Hello from child";
    write(fd[1], msg, strlen(msg));
    close(fd[1]);
    exit(0);
  } else {
    close(fd[1]); // close write end
    char buf[1024];
    int n = read(fd[0], buf, sizeof(buf));
    cout << "Parent received: " << buf << endl;
    close(fd[0]);
    wait(NULL);
  }
  return 0;
}

