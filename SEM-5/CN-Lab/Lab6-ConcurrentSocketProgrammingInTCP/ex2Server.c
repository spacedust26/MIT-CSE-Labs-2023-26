#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#define PORTNO 10202

int server_fd, new_socket, addrlen, valread;
struct sockaddr_in address;
char str[100];
char result[100];
char msg[100];

void CreateServerSocket() {
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORTNO);
    addrlen = sizeof(address);
}

void PerformServerTask() {
    bind(server_fd, (struct sockaddr *)&address, addrlen);
    printf("Server Waiting....\n");
    listen(server_fd, 5);
    while (1) {
        new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen);
        if (fork() == 0) { // Child process
            close(server_fd); // Child does not need the listening socket
            memset(str, 0, sizeof(str));
            valread = read(new_socket, str, sizeof(str) - 1);
            if (valread < 0) {
                perror("Read failed");
                close(new_socket);
                exit(1);
            }


            int length = strlen(str);
            for (int i = 0; i < length; i++) {
                if (str[i] != '0') {
                    for (int j = i + 1; j < length; j++) {
                        if (str[i] == str[j]) {
                            str[j] = '0';
                        }
                    }
                }
            }

            int s = 0;
            for (int k = 0; k < length; k++) {
                if (str[k] != '0') {
                    result[s++] = str[k];
                }
            }
            result[s] = '\0';

            memset(msg, 0, sizeof(msg));
            sprintf(msg, "The result of the operation is: %s", result);

            send(new_socket, result, strlen(result), 0);

            close(new_socket);
            exit(0);
        } else {
            close(new_socket);
        }
    }
}

int main() {
    CreateServerSocket();
    PerformServerTask();
    shutdown(server_fd, SHUT_RDWR);
    return 0;
}
