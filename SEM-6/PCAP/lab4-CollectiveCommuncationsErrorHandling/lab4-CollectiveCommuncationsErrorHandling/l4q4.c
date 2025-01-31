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
    int rank, size, error_code, num1, num2, arr[4], i=0, j=0;
    char str[4];
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Errhandler_set(MPI_COMM_WORLD,MPI_ERRORS_RETURN);

    if(rank == 0){
        printf("Enter string: ");
        gets(str);
    }
    num1 = rank + 1;
    error_code = MPI_Scan(&num1, &num2, 1, MPI_INT, MPI_SUM, MPI_COMM_WORLD);
    if(rank == 0) ErrorHandler(error_code);
    error_code = MPI_Gather(&num2, 1, MPI_INT, arr, 1, MPI_INT, 0, MPI_COMM_WORLD);
    if(rank == 0) ErrorHandler(error_code);
    if(rank == 0){
        int totalSize = size * (size + 1) / 2;
        for(int i = 0; i <= totalSize; i++){
            if(i == arr[j]) j++;
            printf("%c", str[j]);
        }
        printf("\n");
    }
    MPI_Finalize();
    return 0;
}