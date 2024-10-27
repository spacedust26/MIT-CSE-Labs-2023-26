//1. File copy program 
// Create a file called file.in with contents you want to copy

#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/stat.h>
int main(){
  char c;
  int in = open("file.in", O_RDONLY);
  int out = open("file.out", O_WRONLY|O_CREAT, S_IRUSR|S_IWUSR);
  while(read(in, &c, 1) == 1) write(out, &c, 1);
  exit(0);
}