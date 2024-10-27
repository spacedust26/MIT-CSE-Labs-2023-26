// 5.Write a program to copy character-by character copy is accomplished using calls to the functions referenced in stdio.h

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<limits.h>
void main(int argc,char* argv[]){
  if(argc != 3){
    printf("Insufficient Arguments\n");
    exit(1);
  }
  int fd=open(argv[1],O_RDONLY);
  int fl=open(argv[2],O_CREAT|O_WRONLY,S_IRUSR|S_IWUSR);
  if(fd==-1){
    printf("File Not Found\n");
    exit(1);
  }
  char c;
  while(read(fd,&c,1)==1){
    write(fl,&c,1);
  }
}