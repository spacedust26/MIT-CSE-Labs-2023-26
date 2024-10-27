// 2. Write a program to print the lines of a file that contain a word given as the program argument (a simple version of grep UNIX utility).

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<limits.h>
#define MAX_LINE_LENGTH 1024

//First argument is the word to be searched for
//Second argument is the filename
int main(int argc, char *argv[]){
   int in;
   if((in = open(argv[2], O_RDONLY)) == -1){
    write(2, "Error opening the file", 18);
    exit(1);
   }
   
   char c[200];
   int i = 0;
   
   while(read(in, c+i, 1) > 0){
    while(*(c + i) != '\n'){
      i++;
      read(in, c+i, 1);
    }
    if(strstr(c, argv[1]) != NULL) write(1, c, i+1);
    i=0;
    memset(c,0,100);
   }
   close(in);
   return 0;
}

//to execute - gcc demo.c -o demo
// ./demo "red" file.txt