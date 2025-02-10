// Lab exrecise 2 - Write a MPI program to read 3 X 3 matrix. Enter an element to be searched in the root process. Find the number of occurances of this element in the matrix using three processes.

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
    int rank, size, error_code, mat[3][3], ele, arr[3], count = 0, ans = 0;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Errhandler_set(MPI_COMM_WORLD,MPI_ERRORS_RETURN);

    if(rank == 0){
        printf("Enter values for a 3 X 3 matrix: ");
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                scanf("%d", &mat[i][j]);
            }
        }
        printf("Enter the element to be searched for: ");
        scanf("%d", &ele);
    }
    error_code = MPI_Bcast(&ele, 1, MPI_INT, 0, MPI_COMM_WORLD);
    ErrorHandler(error_code);
    error_code = MPI_Scatter(mat, 3, MPI_INT, arr, 3, MPI_INT, 0, MPI_COMM_WORLD);
    ErrorHandler(error_code);
    for(int i = 0; i < 3; i++){
        if(arr[i] == ele) count++;
    }
    error_code = MPI_Reduce(&count, &ans, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
    ErrorHandler(error_code);
    if(rank == 0) printf("Total number of occurance of element %d is %d.\n", ele, ans);
    MPI_Finalize();
    return 0;
}