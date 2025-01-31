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
    int rank, size, error_code, mat[4][4], ans[4][4], arr1[4], arr2[4];
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Errhandler_set(MPI_COMM_WORLD,MPI_ERRORS_RETURN);

    if(rank == 0){
        printf("Enter values for a 4 X 4 matrix: ");
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                scanf("%d", &mat[i][j]);
            }
        }
    }
    error_code = MPI_Scatter(mat, 4, MPI_INT, arr1, 4, MPI_INT,0, MPI_COMM_WORLD);
    if(rank == 0) ErrorHandler(error_code);
    error_code = MPI_Scan(arr1, arr2, 4, MPI_INT, MPI_SUM, MPI_COMM_WORLD);
    if(rank == 0) ErrorHandler(error_code);
    error_code = MPI_Gather(arr2, 4, MPI_INT, ans,4, MPI_INT, 0, MPI_COMM_WORLD);
    if(rank == 0) ErrorHandler(error_code);
    if(rank == 0){
         for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                printf("%d ", ans[i][j]);
            }
            printf("\n");
        }
    }
    MPI_Finalize();
    return 0;
}