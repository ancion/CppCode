#include <stdlib.h>
#include <iostream>
#include <sys/epoll.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_EPOLL 10
#define BUF_SIZE 1024

using namespace std;


int main (int argc, char *argv[]) {  

  int sock_client, epfd, nfds;
  epoll_event event, events[10];
  // server addr
  struct sockaddr_in serv_addr;


  // 1.构建 socket
  sock_client = socket(AF_INET, SOCK_STREAM, IPPROTO_IP);
  if (sock_client < 0){
    cout << "create client socket error" << endl;
    return -1;
  }

  serv_addr.sin_port = htons(PORT);
  serv_addr.sin_family = AF_INET;

  int rt = inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);
  if (rt < 0) {
    cout << "Invalid ip address" << endl;
    return -1;
  }


  // 2.connect 
  rt = connect(sock_client, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
  if (rt < 0) {
    cout << "connect server error" << endl;
    return -1;
  }

  cout << "connected to server " << endl;

  epfd = epoll_create(MAX_EPOLL);
  if (epfd < 0) {
    cout << "epoll create erorr" << endl;
    return -1;
  }

  event.events = EPOLLIN;
  event.data.fd = sock_client;

  rt = epoll_ctl(epfd, EPOLL_CTL_ADD, sock_client, &event);
  if(rt < 0) {
    cout << "epoll ctl error" << endl;
    return -1;
  }

  while (true) {

    nfds = epoll_wait(epfd, events, MAX_EPOLL, -1);
    if (nfds == -1) {
      cout << "epoll wait failed" << endl;
      return -1;
    }

    for (int i = 0; i < nfds; i++) {
      if (events[i].data.fd == sock_client) {
        char buf[BUF_SIZE];
        int bytes = read(events[i].data.fd, buf, BUF_SIZE);
        if (bytes < 0) {
          cout << "read error : {} "<< bytes << endl;
          close(events[i].data.fd);
          break;
        }
        if (bytes == 0) {
          cout << "server side closed connection" << endl;
          close(events[i].data.fd);
          break;
        }
        cout << "Receive:" << buf << endl;
        sleep(1);
        send(events[i].data.fd, buf, bytes, 0);
      }
    }
  }
  close(epfd);
  return 0;
}
