// You are tasked with developing a secure communication system where a client and a server exchange a symmetric encryption key securely over a network. The exchanged key will then be used to encrypt and decrypt messages between the client and server.  
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdlib.h>
#define PORTNO 10200

int main() {
    int sockfd, newsockfd, clilen, key, n;
    char buff[256];
    struct sockaddr_in seraddr, cliaddr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    seraddr.sin_family = AF_INET;
    seraddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    seraddr.sin_port = htons(PORTNO);

    bind(sockfd, (struct sockaddr *)&seraddr, sizeof(seraddr));
    listen(sockfd, 5);
    printf("Server waiting...\n");

    while (1) {
      socklen_t clilen = sizeof(cliaddr);
      newsockfd = accept(sockfd, (struct sockaddr *)&cliaddr, &clilen);

      if (fork() == 0) {
        close(sockfd);
        while (1) {
          read(newsockfd, &key, sizeof(key));
          memset(buff, 0, sizeof(buff)); 
          n = read(newsockfd, buff, sizeof(buff) - 1);
          buff[n] = '\0';
          printf("\nEncrypted text from Client: %s\n", buff);
          for (int i = 0; buff[i] != '\0'; i++) {
            buff[i] = ((buff[i] - key + 256) % 256) ^ key;  // Reverse operations to decrypt
          }
          printf("Decrypted text: %s\n", buff);
          write(newsockfd, buff, strlen(buff) + 1);
        }
        close(newsockfd);
        exit(0);
      } else {
          close(newsockfd);
      }
    }
    close(sockfd);
    return 0;
}