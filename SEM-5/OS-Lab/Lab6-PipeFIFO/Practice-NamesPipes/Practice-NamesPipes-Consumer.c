// Producer consumer problem using named pipes
//CONSUMER
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<limits.h>
#include<assert.h>

#define FIFO_NAME "/home/spacedust/Desktop/os_lab/my_fifo"
#define BUFFER_SIZE PIPE_BUF

int main(){
  char buffer[BUFFER_SIZE + 1];
  int bytes_read = 0, res;
  
  memset(buffer, '\0', sizeof(buffer));
  printf("Process %d opening FIFO O_RDONLY\n", getpid());
  int pipe_fd = open(FIFO_NAME, O_RDONLY);
  printf("Process %d result %d\n", getpid(), pipe_fd);
  
  if(pipe_fd != -1){
    do{
      res = read(pipe_fd, buffer, BUFFER_SIZE);
      bytes_read += res;
    }while(res > 0);
    close(pipe_fd);
  }else exit(EXIT_FAILURE);
  printf("Process %d finished, %d bytes read\n", getpid(), bytes_read);
  exit(EXIT_SUCCESS);
}