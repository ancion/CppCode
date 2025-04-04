//
// 共享内存 + 信号量的方式来实现进程之间的通信
//

#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <iostream>
#include <cstring>
#include <unistd.h>

using namespace std;


// 共享内存结构
struct ShmData {
  int counter;
  char message[100];
};

int main() {

  key_t key = ftok("/tmp", 'A');
  int shmId = shmget(key, sizeof(ShmData), 0666 | IPC_CREAT);

  ShmData *data = (ShmData*) shmat(shmId, NULL,0);

  // 初始化信号量
  int semId = semget(key, 1, 0666 | IPC_CREAT);
  semctl(semId, 0, SETVAL, 1); // 初始值1(互斥锁)
  
  // P 操作(获取锁)
  struct sembuf lock = {0, -1, 0}; 
  // V 操作(释放锁)
  struct sembuf unlock = { 0, 1, 0};


  // 子进程(写入数据)
  if (fork() == 0) {
    semop(semId, &lock, 1); // 加锁
    data -> counter = 42;
    strcpy(data -> message, "Hello from child!");
    semop(semId, &unlock, 1); // 解锁
  }else { // 父进程(读取数据)
    sleep(1); // 等待子进程写入数据
    semop(semId, &lock, 1); // 加锁
    cout << "Counter: " << data -> counter << endl;
    cout << "Message: " << data -> message << endl;
    semop(semId, &unlock, 1); // 解锁
    shmdt(data);
    shmctl(shmId, IPC_RMID, NULL); // 清理共享内存
  }
}
