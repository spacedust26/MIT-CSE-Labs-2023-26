// Sample exercise - Write a MPI program to read N values of the array in the root process. Distribute these N values among N processes. Every process finds the square of the values it received. Let every process return these values to the root and root process gathers and prints the result. Use collective communication routines.

#include<stdio.h>
#include "mpi.h"

int main(int argc, char *argv[]){
  int rank, size, num;
  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  int n = size;
  int arr[n], brr[n];
  if(rank == 0){
    printf("Enter n(size) values of the array: ");
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
  }
  MPI_Scatter(arr, 1, MPI_INT, &num, 1, MPI_INT, 0, MPI_COMM_WORLD);
  printf("Process %d received %d after scatter.\n", rank, num);
  num = num * num;
  MPI_Gather(&num, 1, MPI_INT, brr,1, MPI_INT, 0, MPI_COMM_WORLD);
  if(rank == 0){
    printf("Printing the elements after gathering: ");
    for(int i = 0; i < n; i++) printf("%d ", brr[i]);
  }
  MPI_Finalize();
  return 0;
}