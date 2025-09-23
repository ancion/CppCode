#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sys/epoll.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

using namespace std;

#define MAX_EVENTS 10
#define PORT 8080
#define BUFFER_SIZE 1024


int main (int argc, char *argv[]) {


  struct epoll_event ev, events[MAX_EVENTS];

  int listen_socket, conn_sock, epollfd, nfds;

  struct sockaddr_in address;

  // 
  listen_socket = socket(AF_INET, SOCK_STREAM, 0);

  if (listen_socket == -1) {
    cout << "socket create failed" << endl;
    exit(-1);
  }

  // 设置 socket 选项
  int opt = 1;
  int rt = setsockopt( listen_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

  if(rt == -1)  {
    cout << "setsockopt failed" << endl;
    exit(-1);
  }

  // 设置 socket 地址 (ipv4)
  address.sin_family = AF_INET;
  // 端口，注意网络字节序与主机字节序的对齐
  address.sin_port = htons(PORT);
  // 本地调试地址
  address.sin_addr.s_addr = INADDR_ANY;

  // 绑定监听
  rt = bind (listen_socket, (struct sockaddr*) &address, sizeof(address));
  if (rt < 0) {
    cout << "bind failed" << endl;
    exit(-1);
  }

  // 监听
  rt = listen(listen_socket, 10);
  if (rt < 0) {
    cout << "listen failed" << endl;
    exit(-1);
  }

  // 创建 epoll
  epollfd = epoll_create1(0);  
  if (epollfd == -1) {
    cout << "epoll create failed" << endl;
    exit(-1);
  }

  // 添加事件
  ev.events = EPOLLIN;
  ev.data.fd = listen_socket;


  rt = epoll_ctl(epollfd, EPOLL_CTL_ADD, listen_socket, &ev);
  if (rt == -1) {
    cout << "epoll_ctl failed" << endl;
    exit(-1);
  }

  cout << "Server started ... on port "  << PORT << endl;
  while(true) {
    nfds = epoll_wait(epollfd, events, MAX_EVENTS, -1);
    if (nfds == -1) {
      cout << "epoll_wait failed" << endl;
      exit(-1);
    }
    for (int i = 0; i < nfds; i++) {
      if (events[i].data.fd == listen_socket) {
        conn_sock = accept(listen_socket, NULL, NULL);
        if (conn_sock == -1) {
          cout << "accept failed" << endl;
          exit(-1);
        }
        epoll_event epoll_e;
        epoll_e.events = EPOLLIN | EPOLLET;
        epoll_e.data.fd = conn_sock;

        rt = epoll_ctl(epollfd, EPOLL_CTL_ADD, conn_sock, &epoll_e);
        if (rt == -1) {
          cout << "epoll_ctl failed" << endl;
          exit(-1);
        }
      } else {
        char buffer[BUFFER_SIZE];
        int bytes_read = read(events[i].data.fd, buffer, BUFFER_SIZE);
        if (bytes_read < 0) {
          close(events[i].data.fd);
          cout << "raed failed" << endl;
          continue;
        }else if (bytes_read == 0) { // 断开连接的时候会触发一个事件, 读取到的字节数量为 0 
          close(events[i].data.fd);
          cout << "Client disconnected" << endl;
          continue;
        }else {
          buffer[bytes_read] = '\0';
          cout << buffer << endl;
          write(events[i].data.fd, &buffer, bytes_read);
        }
      }
    }
  }

  close(listen_socket);
  return 0;
} 
