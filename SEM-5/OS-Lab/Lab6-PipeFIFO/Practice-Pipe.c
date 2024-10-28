// Transfer data using pipes
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<limits.h>

int main(int argc, char **argv){
  int n;
  int fd[2];
  char buf[1025];
  char *data = "Hello...this is sample data";
  pipe(fd);
  write(fd[1], data, strlen(data));
  if((n = read(fd[0], buf, 1024)) >= 0){
    buf[n] = 0;
    printf("Read %d bytes from the pipe: %s", n, buf);
  }else perror("read");
  exit(0);
}