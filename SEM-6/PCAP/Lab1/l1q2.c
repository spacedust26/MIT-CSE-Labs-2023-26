#include<stdio.h>
#include<mpi.h>

int main(int argc, char *argv[]){
    int rank, size;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    if(rank % 2) printf("Rank %d: World\n", rank);
    else printf("Rank: %d, Hello\n", rank);
    MPI_Finalize();
    return 0;
}