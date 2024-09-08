//UDP server code - client send the message to the server, server echoes back the message to the client
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>

#define PORT 12001

int main(){
  struct sockaddr_in seraddr, cliaddr;
  int n;
  char buf[256];
  //socket
  int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
  seraddr.sin_family = AF_INET;
  seraddr.sin_addr.s_addr = inet_addr("127.0.0.1");
  seraddr.sin_port = htons(PORT);
  //bind
  bind(sockfd, (struct sockaddr*)&seraddr, sizeof(seraddr));
  //receive
  int m = recvfrom(sockfd, buf, sizeof(buf), 0, (struct sockaddr*)& cliaddr, sizeof(cliaddr));
  printf("Message sent to server is %s", buf);
  int m = recvfrom(sockfd, buf, sizeof(buf), 0, (struct sockaddr*)& cliaddr, sizeof(cliaddr));
}