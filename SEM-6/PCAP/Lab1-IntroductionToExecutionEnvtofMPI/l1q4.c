//Write a program in MPI to toggle character of a given string indexed by rank of the process. Hint: Suppose the string is "HeLLO" and there are 5 processes, then process 0 toggles 'H' to 'h', process 1 toggles 'e' to 'E' and so on.

#include<stdio.h>
#include<mpi.h>
#include<string.h>


char toggle(char c) {
    if(c >= 'A' && c <= 'Z') c += 32;
    else if(c >= 'a' && c <= 'z') c -= 32;
    return c;
}

int main(int argc, char *argv[]){
    int rank, size;
    char str[6] = "HELLO";
    char ans[6] = "";
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    ans[rank] = toggle(str[rank]);
    printf("Rank %d:%c -> %c\n",rank, str[rank], ans[rank]);
    MPI_Finalize();
    return 0;
}