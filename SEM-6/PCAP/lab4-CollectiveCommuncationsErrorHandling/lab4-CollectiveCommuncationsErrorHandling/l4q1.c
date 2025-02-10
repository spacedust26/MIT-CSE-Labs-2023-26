// Lab exercise 1 -Write a MPI program using N processes to find 1! + 2! + .... + N!. Use scan. Also handle different errors using error handling routines.

#include<stdio.h>
#include "mpi.h"

void ErrorHandler(int err_code) {
    if(err_code != MPI_SUCCESS) {
        char error_string[BUFSIZ];
        int length_err_string, err_class;
        MPI_Error_class(err_code, &err_class);
        MPI_Error_string(err_code, error_string, &length_err_string);
        printf("Error: %d %s\n", err_class, error_string);
    }
}

int main(int argc, char *argv[]){
    int rank, size, factprod = 1, factsum, i, value, error_code;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Errhandler_set(MPI_COMM_WORLD, MPI_ERRORS_RETURN);

    value = rank + 1;
    error_code = MPI_Scan(&value, &factprod ,1, MPI_INT, MPI_PROD,MPI_COMM_WORLD);
    ErrorHandler(error_code);
    printf("Process %d: %d\n", rank, factprod);

    error_code = MPI_Scan(&factprod, &factsum, 1,MPI_INT, MPI_SUM, MPI_COMM_WORLD);
    ErrorHandler(error_code);

    if(rank == size -1) printf("Sum of all factorials is %d\n", factsum);
    MPI_Finalize();
    return 0;
}