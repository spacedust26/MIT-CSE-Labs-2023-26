#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 10203
#define rows 3
#define cols 3
#define buf 100

int main() {
    int sd;
    char buf[buf];
    struct sockaddr_in sadd, cadd;
    int matrix[rows][cols];
    int row_counter = 0;
    int len = sizeof(cadd);

    sd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    sadd.sin_family = AF_INET;
    sadd.sin_addr.s_addr = inet_addr("127.0.0.1");
    sadd.sin_port = htons(PORT);

    if (bind(sd, (struct sockaddr *)&sadd, sizeof(sadd)) < 0) {
        perror("Bind failed");
        close(sd);
        exit(EXIT_FAILURE);
    }

    printf("Server is waiting...\n");

    while (row_counter < rows) {
        memset(buf, 0, buf);

        int m = recvfrom(sd, buf, sizeof(buf) - 1, 0, (struct sockaddr *)&cadd, &len);
        if (m < 0) {
            perror("Receive failed");
            close(sd);
            exit(EXIT_FAILURE);
        }
        buf[m] = '\0';

        int i = 0;
        char *token = strtok(buf, " ");
        while (token != NULL && i < cols) {
            matrix[row_counter][i] = atoi(token);
            token = strtok(NULL, " ");
            i++;
        }
        if (i != cols) {
            fprintf(stderr, "Received incomplete row: %s\n", buf);
            close(sd);
            exit(EXIT_FAILURE);
        }
        row_counter++;
    }

    printf("The received matrix is:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    if (close(sd) < 0) {
        perror("Close failed");
        exit(EXIT_FAILURE);
    }

    return 0;
}