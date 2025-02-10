// Additional Exercise 2 - write a MPI program to find the prime numbers between 1 and 100 using two processes

#include<stdio.h>
#include "mpi.h"

void isPrime(int n){
  int isprime = 1;
  for(int i = 2; i < n ; i++){
    if(n % i == 0){
      isprime = 0;
      break;
    }
  }
  if(isprime) printf("%d is prime.\n", n);
}

int main(int argc, char *argv[]){
  int rank, size;
  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  if(rank == 0) for(int i = 1; i <= 50; i++) isPrime(i);
  else for(int i = 51; i <= 100; i++) isPrime(i);
  MPI_Finalize();
  return 0;
}


