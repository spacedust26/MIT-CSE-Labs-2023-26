// Sample Exrecise - Write a MPI progarm using standard send. The sender process sends a number to the receiver. The second process receives the number and prints it
#include<stdio.h>
#include "mpi.h"

int main(int argc, char *argv[]){
    int rank, size, num;
    MPI_Status status;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if(rank == 0){
        printf("Enter a number: ");
        scanf("%d", &num);
        MPI_Send(&num, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
        printf("Process %d sent %d\n", rank, num);
    }
    else{
        MPI_Recv(&num, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
        printf("Process %d received %d\n", rank, num);
    }
    MPI_Finalize();
    return 0;
}