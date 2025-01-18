#include<mpi.h>
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[]){
	int size,rank,arr[100],num;
	MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Status status;

	if(rank == 0){
		printf("Enter elements of the array of size %d : ",size-1);
		for(int i=0;i<size-1;i++) scanf("%d",&arr[i]);
		int bSize = sizeof(arr);
		int* buf = (int*)malloc(bSize);
		MPI_Buffer_attach(buf,bSize);
		for(int i=0;i<size-1;i++)
			MPI_Bsend(&arr[i],1,MPI_INT,i+1,0,MPI_COMM_WORLD);
		MPI_Buffer_detach(&buf,&bSize);
	}
	else {
		MPI_Recv(&num,1,MPI_INT,0,0,MPI_COMM_WORLD,&status);
		if(rank % 2 == 0)
			printf("Rank %d squaring: Received %d\n",rank,num*num);
		else
			printf("Rank %d cubing: Received %d\n",rank,num*num*num);
	}
    MPI_Finalize();
    return 0;
}