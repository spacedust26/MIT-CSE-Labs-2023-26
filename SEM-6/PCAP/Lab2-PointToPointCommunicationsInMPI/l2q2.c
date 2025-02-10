// Lab exercise 2 - Write a MPI program where the master process (process 0) sends a number to each of the slaves and the slave processes receive the number and prints it. Use standard send.

#include<mpi.h>
#include<stdio.h>

int main(int argc, char* argv[]){
	int size,rank,n;
	MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Status status;

	if(rank == 0){
		printf("Enter number: ");
		scanf("%d",&n);
		printf("Process %d: Sending number %d\n",rank, n);
		for(int i=1;i<size;i++) MPI_Send(&n,1,MPI_INT,i,0,MPI_COMM_WORLD);
	}
	else{
		MPI_Recv(&n,1,MPI_INT,0,0,MPI_COMM_WORLD,&status);
		printf("Process %d: Receiving number %d\n",rank,n);
	}
    MPI_Finalize();
    return 0;
}