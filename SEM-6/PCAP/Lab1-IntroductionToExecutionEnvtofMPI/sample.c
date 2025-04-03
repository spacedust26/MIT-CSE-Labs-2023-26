//Sample - Write a program in MPI to print total number of process and rank of each process

#include<stdio.h>
#include "mpi.h"

int main(int argc, char *argv[]){
  int rank, size;
  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  printf("My rank is %d in a total of %d processes.\n", rank, size);
  MPI_Finalize();
  return 0;
}