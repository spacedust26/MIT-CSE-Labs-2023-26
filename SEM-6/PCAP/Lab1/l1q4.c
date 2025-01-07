#include<stdio.h>
#include<mpi.h>
#include<string.h>
#include<ctype.h>

int main(int argc, char *argv[]){
    int rank, size;
    char str[6] = "HELLO";
    char ans[6] = "";
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    
    if(rank!=5 && rank != 6){
        ans[rank] = tolower(str[rank]);
        printf("Rank %d:%c -> %c\n",rank, str[rank], ans[rank]);
    }

    if(rank == 5) ans[5] = '\0';
   
    if(rank == 6) printf("Rank %d: %s",rank, ans);
    MPI_Finalize();
    return 0;
}