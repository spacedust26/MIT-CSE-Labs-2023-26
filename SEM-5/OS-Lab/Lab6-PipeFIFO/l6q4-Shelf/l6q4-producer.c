#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<limits.h>
#include<sys/types.h>
#include<sys/stat.h>
#define FIFO_NAME "/tmp/q4_fifo"

int main(){
	int pipe_fd;
	int res;
	int count=5;
	if(access(FIFO_NAME, F_OK)==-1){
		res = mkfifo(FIFO_NAME, 0777);
		if(res!=0){
			fprintf(stderr, "Could not create fifo %s\n", FIFO_NAME);
			exit(1);
		}
	}
	
	while(1){
		
		printf("Current product count = %d\n", count);

		//open in wronly
		pipe_fd = open(FIFO_NAME, O_WRONLY);
		res = write(pipe_fd, &count, sizeof(int));
		close(pipe_fd);

		//open in rdonly
		pipe_fd = open(FIFO_NAME, O_RDONLY);
		res = read(pipe_fd, &count, sizeof(int));
		if(count<5){
			printf("Do you want to add to the current count(%d) (Enter 1 to add)?", count);
			int flag=0;
			scanf("%d", &flag);
			if(flag)
				count++;
		}
		close(pipe_fd);
	}
}