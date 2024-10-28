// Producer consumer problem using named pipes
//PRODUCER
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
#define TEN_MEG (1024 * 1024 * 10)

int main(){
  int bytes_sent = 0, res;
  char buffer[BUFFER_SIZE + 1];
  
  if(access(FIFO_NAME, F_OK) == -1){ //create FIFO if it doesn't exist
    res = mkfifo(FIFO_NAME, 0777);
    if(res != 0){
      fprintf(stderr, "Could not create fifo %s\n", FIFO_NAME);
      exit(EXIT_FAILURE);
    }
  }
  
  printf("Process %d opening FIFO O_WRONLY\n", getpid());
  int pipe_fd = open(FIFO_NAME, O_WRONLY); // open fifo for writing
  printf("Process %d result %d\n", getpid(), pipe_fd);
  
  if(pipe_fd != -1){
    while(bytes_sent < TEN_MEG){
      res = write(pipe_fd, buffer, BUFFER_SIZE);
      if(res == -1){
        fprintf(stderr, "Write error on pipe\n");
        exit(EXIT_FAILURE);
      }
      bytes_sent += res;
    }
    (void)close(pipe_fd); //close fifo
  }else exit(EXIT_FAILURE);
  printf("Process %d finished\n", getpid());
  exit(EXIT_SUCCESS);
}
