// 基于消息队列的进程间通信
// 多个进程之间想要同行，并且需要避免竞争的时候，使用管道就不合适了
// 这时候需要使用消息队列
// ------------------------------------------------------------
// 1. 想要使用消息队列在进程间通信，就必须在内核空间创建一个消息队列,
//    大小默认是 16 kb 
// 2. 当创建好消息队列之后，A 进程就可以往消息队列中发送消息, 
//    消息的格式默认是类型 + 正文
// 3. 当消息队列满的时候，如果 A 进程还想往队列中写消息，
//    那么此时 A 进程就会休眠
// 4. B 进程可以通过消息的类型从消息队列中读取消息, 读出的消息在消息队列中会移除
//    如果 B 进程读取的消息类型在 消息队列中不存在，那么 B 进程会进入休眠


#include <iostream>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <cstring>
#include <sys/wait.h>
#include <unistd.h>

using namespace std;


// 消息队列结构
struct Message {
  long type; // 消息类型
  char text[100]; // 消息内容
};

int main() {
  key_t key = ftok("/tmp", 'A');
  int msgId = msgget(key, 0666 | IPC_CREAT);

  if (fork() == 0) { // child (writer)
    sleep(1);
    Message msg;
    msg.type = 1;
    strcpy(msg.text, "Hello from writer");
    msgsnd(msgId, &msg, sizeof(msg), 0);
    exit(0);
  }else { // parent (reader)
    sleep(2);
    Message msg;
    msgrcv(msgId, &msg, sizeof(msg), 1, 0);
    cout << "Reader received: " << msg.text << endl;
    msgctl(msgId, IPC_RMID, NULL);
    wait(NULL);
  }
  return 0;
}
