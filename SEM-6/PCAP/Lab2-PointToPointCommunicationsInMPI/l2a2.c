// Additional Exercise 2 - Write a MPI program to read value of N in the root process. Using N processes, including root, find out 1! + (1+2) + 3! + (1+2+3+4) + 5! + (1+2+3+4+5+6) and print the result in the root process.

#include <stdio.h>
#include <stdlib.h>
#include "mpi.h"

int factorial(int n) {
    int fact = 1;
    for (int i = 1; i <= n; i++)
        fact *= i;
    return fact;
}

int sum_natural(int n) {
    return (n * (n + 1)) / 2;
}

int main(int argc, char* argv[]) {
    int rank, size, N;
    
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank == 0) {
        printf("Enter value of N: ");
        scanf("%d", &N);
        for (int i = 1; i < size; i++) MPI_Send(&N, 1, MPI_INT, i, 0, MPI_COMM_WORLD);
    } else {
        MPI_Recv(&N, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    }

    int local_result;
    if (rank & 1) local_result = factorial(rank);
    else local_result = sum_natural(rank);

    if (rank != 0) {
        MPI_Send(&local_result, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    } else {
        int total_sum = local_result;
        int received_value;
        for (int i = 1; i < size; i++) {
            MPI_Recv(&received_value, 1, MPI_INT, i, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            total_sum += received_value;
        }
        printf("Final result: %d\n", total_sum);
    }

    MPI_Finalize();
    return 0;
}
