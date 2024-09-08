#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#define PORTNO 10202

int sock, addrlen, client_fd, valread;
struct sockaddr_in address;
char str[100];
char result[100];

void CreateClientSocket() {
    sock = socket(AF_INET, SOCK_STREAM, 0);
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr("127.0.0.1");
    address.sin_port = htons(PORTNO);
    addrlen = sizeof(address);
}

void PerformClientTask() {
    client_fd = connect(sock, (struct sockaddr *)&address, addrlen);
    if (client_fd == -1) {
        perror("\nCLIENT ERROR");
        exit(1);
    }
    printf("Enter string: ");
    scanf("%s", str);

    send(sock, str, strlen(str), 0);

    memset(result, 0, sizeof(result));
    valread = read(sock, result, sizeof(result) - 1);
    if (valread < 0) {
        perror("Read failed");
        close(sock);
        exit(1);
    }
    result[valread] = '\0';
    printf("%s\n", result);
}

int main() {
    CreateClientSocket();
    PerformClientTask();
    close(sock);
    return 0;
}
