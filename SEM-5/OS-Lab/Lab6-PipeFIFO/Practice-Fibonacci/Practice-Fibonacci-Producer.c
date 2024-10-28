// Write a program to generate fibonacci sequence from producer to consumer one by one
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/stat.h>

#define FIFO_NAME "/home/spacedust/Desktop/os_lab/practice_fifo"

void generate_fibonacci(int n){
    int a = 0, b = 1, c;
    int pipeid = open(FIFO_NAME, O_WRONLY);
    if(pipeid == -1){
        perror("open pipe");
        exit(EXIT_FAILURE);
    }

    for(int i=0; i <n; i++){
        write(pipeid, &a, sizeof(int));
        c = a + b;
        a = b;
        b = c;
    }
    close(pipeid);
}

int main(){
    if(access(FIFO_NAME, F_OK) == -1){
        if(mkfifo(FIFO_NAME, 0666) != 0){
            perror("mkfifo");
            exit(EXIT_FAILURE);
        }
    }
    int n;
    printf("Enter the number of fibonacci numbers to generate: ");
    scanf("%d", &n);
    generate_fibonacci(n);
    return 0;
}