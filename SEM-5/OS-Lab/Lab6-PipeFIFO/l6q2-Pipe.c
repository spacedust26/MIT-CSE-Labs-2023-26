//Demonstrate creation, writing to, and reading from a pipe.

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main(int argc, char **argv){
    int n, fd[2];
    char buf[BUFFER_SIZE + 1];
    const char *data = "hello... this is sample data";

    if (pipe(fd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    if (write(fd[1], data, strlen(data)) == -1) {
        perror("write");
        exit(EXIT_FAILURE);
    }

    if (close(fd[1]) == -1) {
        perror("close write end");
        exit(EXIT_FAILURE);
    }

    if ((n = read(fd[0], buf, BUFFER_SIZE)) == -1) {
        perror("read");
        exit(EXIT_FAILURE);
    }

    buf[n] = '\0';
    printf("Read %d bytes from the pipe: \"%s\"\n", n, buf);

    if (close(fd[0]) == -1) {
        perror("close read end");
        exit(EXIT_FAILURE);
    }

    return 0;
}