//Write a producer and consumer program in C using the FIFO queue. The producer should write a set of 4 integers into the FIFO queue and the consumer should display the 4 integers.

//PRODUCER

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
#define TEN_MEG (4*sizeof(int))

int main(){
	int pipe_fd;
	int res;
	int open_mode = O_WRONLY;
	int bytes_sent=0;
	char buffer[BUFFER_SIZE+1];
	if(access(FIFO_NAME, F_OK)==-1){
		res = mkfifo(FIFO_NAME, 0777);
		if(res!=0){
			fprintf(stderr, "Could not create fifo %s\n", FIFO_NAME);
			exit(1);
		}
	}
	printf("Process %d opening FIFO O_WRONLY\n", getpid());
	pipe_fd = open(FIFO_NAME, open_mode);
	printf("Process %d result %d\n", getpid(), pipe_fd);
	int i=1;
	if(pipe_fd!=-1){
		while(bytes_sent<TEN_MEG && i<=4){
			res=write(pipe_fd, &i, sizeof(int));
			i++;
			if(res==-1){
				fprintf(stderr, "Write error on pipe\n");
				exit(1);
			}
			bytes_sent+= res;
		}
		(void)close(pipe_fd);
	}
	else{
		exit(1);
	}
	printf("process %d finished\n", getpid());
	exit(0);
}