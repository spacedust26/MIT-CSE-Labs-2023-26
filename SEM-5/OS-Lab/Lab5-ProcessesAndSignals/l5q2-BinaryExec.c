// 2. Write a C program to load the binary executable of the previous program in a child process using the exec system call.
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
int main(){
    pid_t pid;
    pid = fork();
    if (pid < 0) {
        fprintf(stderr,"Fork Failed");
        exit(-1);
    }
    else if(pid == 0){
        execlp("./q1blockparent", "q1blockparent", NULL); 
    }
    else{
        wait (NULL);
        write(1,"Complete\n",10);
        exit(0);
    }
}