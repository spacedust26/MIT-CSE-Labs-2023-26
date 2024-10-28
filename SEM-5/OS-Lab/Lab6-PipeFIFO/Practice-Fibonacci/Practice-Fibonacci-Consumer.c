#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/stat.h>

#define FIFO_NAME "/home/spacedust/Desktop/os_lab/practice_fifo"

int main(){
    int pipeid = open(FIFO_NAME, O_RDONLY);
    if(pipeid == -1){
        perror("open pipe");
        exit(EXIT_FAILURE);
    }
    int num;
    printf("Fibonacci numbers received:\n");
    while(read(pipeid, &num, sizeof(int)) > 0) printf("%d\n", num);
    close(pipeid);
    return 0;
}
