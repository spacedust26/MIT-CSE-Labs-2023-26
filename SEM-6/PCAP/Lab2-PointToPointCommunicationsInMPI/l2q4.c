//Lab exercise 4 - Write a MPI program to read an integer value in the root process. Root process sends this value to process1, process1 sends this value to process2 and so on. Last process sends the value back to root process. When sending the value each process will first increment the received value by one. Write the program using point to point communication routines.

#include "mpi.h"
#include <stdio.h>

int main(int argc, char *argv[]){
	int rank, size, x;
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Status status;

	if(rank==0){
		printf("Enter integer : ");
		scanf("%d", &x);
		MPI_Ssend(&x, 1, MPI_INT, rank+1, 1, MPI_COMM_WORLD);
		MPI_Recv(&x,1,MPI_INT,(size-1),1,MPI_COMM_WORLD,&status);
		printf("Process %d: Received %d from process %d\n",rank, x, size-1);
	}
	else{
		MPI_Recv(&x,1,MPI_INT,(rank-1),1,MPI_COMM_WORLD,&status);
		printf("Process %d: Received %d from process %d\n",rank, x, rank-1);
		x += 1;
		if(rank == (size-1)) MPI_Ssend(&x, 1, MPI_INT, 0, 1, MPI_COMM_WORLD);
		else MPI_Ssend(&x, 1, MPI_INT, rank+1, 1, MPI_COMM_WORLD);
	} 
	MPI_Finalize();
    return 0;
}