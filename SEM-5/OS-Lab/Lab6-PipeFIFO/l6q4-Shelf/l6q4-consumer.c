#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<limits.h>
#include<sys/types.h>
#include<sys/stat.h>
#define FIFO_NAME "/tmp/q4_fifo"
#define BUFFER_SIZE PIPE_BUF

int main(){
	int pipe_fd;
	int res;
	int count;
	while(1){

		pipe_fd = open(FIFO_NAME, O_RDONLY);
		res = read(pipe_fd, &count, sizeof(int));
		close(pipe_fd);
		printf("Current count = %d\n", count);
		if(count>0){
			printf("Do you want to consume 1 product? (Enter 1 to consume)");
			int flag=0;
			scanf("%d", &flag);
			if(flag)
				count--;
		}
		pipe_fd = open(FIFO_NAME, O_WRONLY);
		res = write(pipe_fd, &count, sizeof(int));
		close(pipe_fd);
	}
}