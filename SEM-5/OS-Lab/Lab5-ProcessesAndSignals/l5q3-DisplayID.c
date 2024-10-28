// 3. Write a program to create a child process. Display the process IDs of the process, parent and child (if any) in both the parent and child processes.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<limits.h>
void main() {
    int status;
    pid_t pid;
    pid = fork();
    if(pid == -1)
        printf("\nERROR child not created");
    else if (pid == 0){
        printf("\nI'm the child!");
        printf("\npid is %d\nppid is %d\n", getpid(), getppid());
        exit(0);
    }
    else{
        wait(&status);
        printf("\nI'm the parent!");
        printf("\npid is %d\nppid is %d\n", getpid(), getppid());
    }
}