// You are tasked with developing a secure communication system where a client and a server  exchange a symmetric encryption key securely over a network. The exchanged key will then be used to encrypt and decrypt messages between the client and server.  
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<fcntl.h>
#include<unistd.h>

#define PORTNO 10200

int main(){
  int key, n;
  char str[256], buff[256];
  struct sockaddr_in address;
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = inet_addr("127.0.0.1");
  address.sin_port = htons(PORTNO);

  connect(sockfd, (struct sockaddr *)&address, sizeof(address));

  while(1){
    printf("Enter integer secret key: ");
    scanf("%d", &key);
    write(sockfd, &key, sizeof(key));

    getchar();
    printf("Enter text: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';
    for (int i = 0; str[i] != '\0'; i++) {
      str[i] = ((str[i] ^ key) + key) % 256;
    }

    write(sockfd, str, strlen(str) + 1);

    n = read(sockfd, buff, sizeof(buff) - 1);
    buff[n] = '\0';
    printf("\nFROM SERVER decrypted text is: %s", buff);
    printf("\n");
  }
  close(sockfd);
  return 0;
}