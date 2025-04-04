#include <iostream>
#include <sys/socket.h>
#include <sys/un.h>
#include <sys/wait.h>
#include <unistd.h>
#include <cstring>

using namespace std;

const char* SOCKET_PATH = "/tmp/example.sock";

int main(){
  unlink(SOCKET_PATH);

  int server_fd = socket(AF_UNIX, SOCK_STREAM, 0);
  if (server_fd == -1) {
    perror("socket");
    return 1;
  }

  struct sockaddr_un addr;

  memset(&addr, 0, sizeof(addr));

  addr.sun_family = AF_UNIX;
  strncpy(addr.sun_path, SOCKET_PATH, sizeof(addr.sun_path) - 1);

  if (bind(server_fd, (struct sockaddr*)&addr, sizeof(addr)) == -1) {
    perror("bind");
    return 1;
  }

  if (listen(server_fd, 5) == -1) {
    perror("listen");
    return 1;
  }

  if (fork() == 0) { // client
    sleep(1);
    int client_fd = socket(AF_UNIX, SOCK_STREAM, 0);
    if (connect(client_fd, (struct sockaddr*)&addr, sizeof(addr)) == -1) {
      perror("connect");
      return 1;
    }
    const char* msg = "Hello from child!";
    write(client_fd, msg, strlen(msg));
    close(client_fd);
    exit(0);
  }else {
    int client_fd = accept(server_fd, NULL, NULL);
    if (client_fd == -1) {
      perror("accept");
      return 1;
    }
    char buf[1024];
    int n = read(client_fd, buf, sizeof(buf));
    buf[n] = '\0';
    cout << "Server received: " << buf << endl;
    close(client_fd);
    close(server_fd);
    unlink(SOCKET_PATH);
    wait(NULL);
  }
  return 0;
}
