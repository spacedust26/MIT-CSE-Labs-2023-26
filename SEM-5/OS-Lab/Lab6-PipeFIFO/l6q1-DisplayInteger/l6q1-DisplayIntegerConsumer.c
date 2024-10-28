// 1. Write a producer and consumer program in C using the FIFO queue. The producer should write a set of 4 integers into the FIFO queue and the consumer should display the 4 integers.

//CONSUMER

#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<limits.h>
#include<sys/types.h>
#include<sys/stat.h>
#define FIFO_NAME "/home/spacedust/Desktop/os_lab/q1_fifo"
#define BUFFER_SIZE PIPE_BUF

int main(){
	int pipe_fd;
	int res;
	int open_mode = O_RDONLY;
	int buffer;
	int bytes_read=0;
	//memset(buffer, '\0', sizeof(buffer));
	printf("process %d opening FIFO O_RDONLY\n", getpid());
	pipe_fd = open(FIFO_NAME, open_mode);
	printf("process %d result %d\n", getpid(), pipe_fd);
	if(pipe_fd!=-1){
		while(1){
			res = read(pipe_fd, &buffer, sizeof(int));
			if(res>0){
				printf("%d\n", buffer);
				bytes_read+=res;
			}
			else break;
		}
		(void)close(pipe_fd);
	}else{
		exit(1);
	}
	printf("Process %d finished, %d bytes read\n", getpid(), bytes_read);
	exit(0);
}