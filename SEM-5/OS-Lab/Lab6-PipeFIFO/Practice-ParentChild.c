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

int main(int argc, char *argv[]){
  int pfd[2]; // holds the 2 file descriptors
  pid_t cpid;
  char buf;
  assert(argc == 2); // check that a single argument is passes
  if(pipe(pfd) == -1){ // create pipe
    perror("pipe");
    exit(EXIT_FAILURE);
  }
  
  cpid = fork(); // fork the process
  if(cpid == -1){
    perror("fork");
    exit(EXIT_FAILURE);
  }
  
  if(cpid == 0){ // child process
    close(pfd[1]); // close the write end
    while(read(pfd[0], &buf, 1) > 0 ) write(STDOUT_FILENO, &buf, 1); // read data into standard output
    write(STDOUT_FILENO, "\n",1); // adding newline character
    close(pfd[0]); // close read end
    exit(EXIT_SUCCESS);
  }
  
  else{ // Parent process
    close(pfd[0]); // close the read end
    write(pfd[1], argv[1], strlen(argv[1])); // write argument to pipe
    close(pfd[1]); // close write end
    wait(NULL); // wait for child process to finish
    exit(EXIT_SUCCESS);
  }
}

// To run
// gcc demo.c -o demo
// ./demo "This is sample text"