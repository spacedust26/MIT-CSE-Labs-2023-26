#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define FIFO_NAME "/tmp/q2_fifo"
#define BUFFER_SIZE 1024

int main() {
    int pipe_fd;
    int res;
    char buffer[BUFFER_SIZE + 1];

    // Check if FIFO exists; if not, create it
    if (access(FIFO_NAME, F_OK) == -1) {
        res = mkfifo(FIFO_NAME, 0777);
        if (res != 0) {
            perror("Could not create FIFO");
            exit(EXIT_FAILURE);
        }
    }

    while (1) {
        // Open FIFO for reading
        printf("Process %d opening FIFO O_RDONLY\n", getpid());
        pipe_fd = open(FIFO_NAME, O_RDONLY);
        if (pipe_fd == -1) {
            perror("Error opening FIFO for reading");
            exit(EXIT_FAILURE);
        }

        // Read from FIFO
        memset(buffer, 0, sizeof(buffer));
        res = read(pipe_fd, buffer, BUFFER_SIZE);
        if (res > 0) {
            printf("Data read from FIFO: %s\n", buffer);
        } else if (res == 0) {
            printf("No data read (FIFO might be empty).\n");
        } else {
            perror("Error reading from FIFO");
        }
        close(pipe_fd);

        // Open FIFO for writing
        printf("Process %d opening FIFO O_WRONLY\n", getpid());
        pipe_fd = open(FIFO_NAME, O_WRONLY);
        if (pipe_fd == -1) {
            perror("Error opening FIFO for writing");
            exit(EXIT_FAILURE);
        }

        // Write to FIFO
        printf("Data to write to FIFO: ");
        if (fgets(buffer, BUFFER_SIZE, stdin) != NULL) {
            size_t len = strlen(buffer);
            if (len > 0 && buffer[len - 1] == '\n') {
                buffer[len - 1] = '\0'; // Remove newline character
            }
            res = write(pipe_fd, buffer, len);
            if (res == -1) {
                perror("Error writing to FIFO");
            }
        } else {
            perror("Error reading input from stdin");
        }
        close(pipe_fd);
    }

    return 0;
}