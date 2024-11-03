// Implement a basic chat application where multiple clients can send and receive messages through a server.
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

#define PORTNO 10200

int sd; 
void* read_messages(void* arg) {
  char output[300];
  while (1) {
    int bytes_read = read(sd, output, sizeof(output) - 1);
    if (bytes_read > 0) {
        output[bytes_read] = '\0'; 
        printf("Received: %s\n", output);
    }
  }
  return NULL;
}

void* write_messages(void* arg) {
  char buf[256];
  while (1) {
      gets(buf); 
      write(sd, buf, strlen(buf));
  }
    return NULL;
}

int main() {
    struct sockaddr_in address;
    sd = socket(AF_INET, SOCK_STREAM, 0);
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr("0.0.0.0");
    address.sin_port = htons(PORTNO);
    if (connect(sd, (struct sockaddr*)&address, sizeof(address)) < 0) {
        perror("Connection failed");
        exit(1);
    }
    pthread_t read_thread, write_thread;
    pthread_create(&read_thread, NULL, read_messages, NULL);
    pthread_create(&write_thread, NULL, write_messages, NULL);
    pthread_join(read_thread, NULL);
    pthread_join(write_thread, NULL);
    close(sd);
    return 0;
}
