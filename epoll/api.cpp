#include <iostream>
#include <unistd.h>
#include <sys/epoll.h>

using namespace std;

int main() {

  int epoll_fd, fd, nfds;

  epoll_fd = epoll_create(10);
  if (epoll_fd == -1) {
    cout << "epoll crate failed" << endl;
    return -1;
  }

  fd = STDIN_FILENO;

  struct epoll_event ev;

  ev.events = EPOLLIN;
  ev.data.fd = fd;

  int re = epoll_ctl(epoll_fd, EPOLL_CTL_ADD, fd, &ev);

  if (re == -1) {
    return -1;
  }

  struct epoll_event events[10];
  while (true) {

    nfds = epoll_wait(epoll_fd, events, 10, -1);
    if (nfds == -1) {
      return -1;
    }
    for (int i = 0; i < nfds; ++i) {
      if(events[i].data.fd == STDIN_FILENO) {
        char buf[512];
        int count = read(events[i].data.fd, buf, size(buf) - 1);
        buf[count] = '\0';
        cout << "receive: " << buf << endl;
      }
    }
  }
}
