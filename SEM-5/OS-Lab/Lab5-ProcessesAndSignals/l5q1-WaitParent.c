// 1.Write a C program to block a parent process until the child completes using a wait system call.
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
        write(2,"ERROR child not created",23);
    else if (pid == 0){
        write(1,"\nI'm the child!",14);
        exit(0);
    }
    else{
        wait(&status);
        write(1,"\nI'm the parent!",15);
        printf("\nChild returned: %d\n",status);
    }
}