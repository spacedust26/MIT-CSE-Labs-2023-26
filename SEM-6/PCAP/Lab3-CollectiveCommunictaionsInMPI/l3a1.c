// Additonal exercise 1 - Write a MPI program to read a value M and N X M number of elements into 1D array in the root, where N is the total number of processes. Find the square of first M numbers, the cube of next M numbers and so on. Print the results in the root

#include <stdio.h>
#include <mpi.h>
#include <math.h>

int main(int argc, char *argv[]) {
    int rank, size, M, N;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    N = size;
    int data[100], local_data[100], result[100];
    if (rank == 0) {
        printf("Enter value of M: ");
        scanf("%d", &M);
        printf("Enter %d numbers: ", N * M);
        for (int i = 0; i < N * M; i++) {
            scanf("%d", &data[i]);
        }
    }
    MPI_Bcast(&M, 1, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Scatter(data, M, MPI_INT, local_data, M, MPI_INT, 0, MPI_COMM_WORLD);
    for (int i = 0; i < M; i++) {
        local_data[i] = pow(local_data[i], rank + 2); 
    }
    MPI_Gather(local_data, M, MPI_INT, result, M, MPI_INT, 0, MPI_COMM_WORLD);
    if (rank == 0) {
        printf("Processed Results:\n");
        for (int i = 0; i < N * M; i++) {
            printf("%d ", result[i]);
        }
        printf("\n");
    }
    MPI_Finalize();
    return 0;
}
