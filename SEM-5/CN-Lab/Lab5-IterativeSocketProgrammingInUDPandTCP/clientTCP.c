// TCP client code - client send the message to the server, server echoes back the message to the client
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
  struct sockaddr_in address;
  int n, result;
  char ch[256], buf[256];
  //socket
  int sockfd = socket(AF_INET, SOCK_STREAm, 0);
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = inet_addr("127.0.0.1");
  address.sin_port = htons(PORT);
  //connect
  result = connect(sockfd, (struct sockaddr*)& address, sizeof(address));
  if(result == -1){
    perror("Client error");
    exit(1);
  }
  //send
  printf("Enter a string: ");
  scanf("%s",ch);
  write(sockfd, ch, strlen(ch));
  //receive
  printf("Message sent from server to client: ");
  while(1){
    n = read(sockfd, buf, sizeof(buf));
    printf("%s",buf);
  }
  //close
  close(sockfd);
}


