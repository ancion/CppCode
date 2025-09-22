#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>


#define PORT 8080
#define BUFFER_SIZE 1024

using namespace std;

int main (int argc, char *argv[]) {
  

  struct sockaddr_in serv_addr;
  int sock = 0;

  char buffer[BUFFER_SIZE] = { 0 };

  if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    printf("\n socket create error \n");
    return -1;
  }

  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(PORT);

  // 将IPv4 地址从文本转换为二进制格式
  if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) < 0 ) {
    printf("\nInvalid address / not support \n");
    return -1;
  }

  // 
  if (connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr))< 0) {
    printf("\nConnect Failed\n");
    return -1;
  }

  printf("Connected to Server \n");

  // 发送消息到服务器
  char* message = "Hello from client";
  send(sock, message, strlen(message), 0);
  printf("Message send %s\n", message);

  // 接受服务器的响应
  int bytes_read = read(sock, buffer, BUFFER_SIZE);
  if(bytes_read > 0) {
    printf("Server reply %s\n", buffer);
  } else {
    printf("No data receiver\n");
  }

  close(sock);
  return 0;
}
