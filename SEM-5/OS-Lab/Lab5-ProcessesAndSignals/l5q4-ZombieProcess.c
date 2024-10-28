// 4.reate a zombie (defunct) child process (a child with exit() call, but no corresponding wait() in the sleeping parent) and allow the init process to adopt it (after parent terminates). Run the process as a background process and run the “ps” command.
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
int main() {
    pid_t pid;
    pid = fork();
    if (pid < 0) {
        fprintf(stderr,"No child.");
        exit(-1);
    }
    else if (pid == 0) {
        printf("\nI'm the child!");
        printf("\npid is %d\nppid is %d", getpid(), getppid());
        exit(0);
    }
    else { 
        sleep(100);
        printf ("\nComplete\n");
        exit(0);
    }
}

//how to run
// gcc demo.c -o demo
// ./demo &
//ps