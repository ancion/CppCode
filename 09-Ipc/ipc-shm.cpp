#include <iostream>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <cstring>
#include <sys/wait.h>
#include <unistd.h>


using namespace std;

// 共享内存的方式来完成进程间通信

int main() {

  key_t key = 1234;
  int shmid = shmget(key, 1024, 0666 | IPC_CREAT);
  if (shmid == -1) {
    perror("shmget");
    return 1;
  }

  char* shm = (char*) shmat(shmid, NULL, 0);
  if (shm == (char*) -1) {
    perror("shmat");
    return 1;
  }

  if (fork() == 0) { // child (writer)
    sleep(1);
    strcpy(shm, "Hello from writer");
    shmdt(shm);
    exit(0);
  }else { // parent (reader)
    sleep(2);
    cout << "Reader received: " << shm << endl;
    shmdt(shm);
    shmctl(shmid, IPC_RMID, NULL);
    wait(NULL);
  }
  return 0;
}
