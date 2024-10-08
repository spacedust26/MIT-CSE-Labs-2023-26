//TCP server code - client send the message to the server, server echoes back the message to the client
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
  //socket
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  seraddr.sin_family = AF_INET;
  seraddr.sin_addr.s_addr = inet_addr("127.0.0.1");
  seraddr.sin_port = htons(PORT);
  //bind
  bind(sockfd, (struct sockaddr*)&seraddr, sizeof(seraddr));
  //listen
  listen(sockfd, 5);
  while(1){
    char buf[256];
    printf("Server is waiting");
    //accept
    newsockfd(sockfd, (struct sockaddr*)&cliaddr, sizeof(cliaddr));
    //receive from client
    n = read(newsockfd, buf, sizeof(buf));
    printf("Message from client received by servers is %s", buf);
    //send to client
    n = write(newsockfd, buf, sizeof(buf));
    //close 
    close(newsockfd);
  }
  //close
  close(sockfd);
}