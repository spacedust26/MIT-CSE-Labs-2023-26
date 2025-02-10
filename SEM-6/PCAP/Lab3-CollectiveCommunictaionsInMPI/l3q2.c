// Lab exercise 2 - Write a MPI program to read an integer value M and NXM elements into a 1D array in the root process where N is the number of processes. Root process sends M elements to each process. Each process finds the average of M elements it received and sends these avergae values to root. Root collects all the values and finds the total average. Use collective communication routines.

#include<stdio.h>
#include<mpi.h>
#include<unistd.h>

int main(int argc, char *argv[]){
	int rank, size, N, M;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	N = size;

	if(rank==0){
        printf("Enter the value of M : ");
        scanf("%d", &M);
    }
    MPI_Bcast(&M, 1, MPI_INT, 0, MPI_COMM_WORLD);
    printf("Process %d received M = %d\n", rank, M);
    int arr_size = N * M;
    int A[arr_size], rcvbuf[M];
    float averages[N];

    if (rank==0){  	
        sleep(1);
        printf("Enter %d array elements : ", arr_size);
        for(int i=0;i<arr_size;i++) scanf("%d",&A[i]);
    }

    MPI_Scatter(A,M,MPI_INT,&rcvbuf,M,MPI_INT,0,MPI_COMM_WORLD);

    float avg=0.0;
    for (int i=0;i<M;i++){
    	avg += rcvbuf[i];
    }
    avg = avg/M;

	MPI_Gather(&avg,1,MPI_INT,averages,1,MPI_INT,0,MPI_COMM_WORLD);

	if(rank==0){
        printf("Gathered results : \n");
        avg = 0.0;
        for(int i=0;i<N;i++){
            printf("%f \n",averages[i]);
            avg += averages[i];
        }
        avg = avg/N;
        printf("Average : %f\n",avg);
    }

    MPI_Finalize();
    return 0;
}