// Write a program to send a matrix to a child process from a parent process using pipes
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){
    int matrix[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
    int fd[2];
    if(pipe(fd) == -1){
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid_t pid = fork();
    if(pid == -1){
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if(pid > 0){
        close(fd[0]); //close read
        write(fd[1], matrix, sizeof(matrix));
        close(fd[1]); //close write
        int status;
        waitpid(pid, &status, 0);
        printf("Parent process (PID: %d) sent the matrix and is now exiting\n", getpid());
    }else{
        close(fd[1]); //close write
        int childMatrix[3][3];
        read(fd[0], childMatrix, sizeof(childMatrix));
        close(fd[0]); //close read
        printf("Child process (PID: %d) recerived the matrix\n", getpid());
        for(int i = 0 ; i < 3 ; i++){
            for(int j = 0; j < 3 ; j++){
                printf("%d", childMatrix[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}