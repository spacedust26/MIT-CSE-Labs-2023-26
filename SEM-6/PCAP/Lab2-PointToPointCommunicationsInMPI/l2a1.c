// Additional Exercise 1 - Write a MPI program to read N elements of an array in the master process. Let N processes including master process check the array values are prime or not

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "mpi.h"

int is_prime(int num) {
    if (num < 2) return 0;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

int main(int argc, char *argv[]) {
    int rank, size, N;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank == 0) {
        printf("Enter number of elements (N): ");
        scanf("%d", &N);
        int arr[N]; 
        printf("Enter %d numbers: ", N);
        for (int i = 0; i < N; i++) {
            scanf("%d", &arr[i]);
        }

        for (int i = 1; i < size; i++) {
            if (i <= N) {
                MPI_Send(&arr[i - 1], 1, MPI_INT, i, 0, MPI_COMM_WORLD);
            }
        }
        for (int i = 1; i < size; i++) {
            if (i <= N) {
                int num, prime_flag;
                MPI_Recv(&prime_flag, 1, MPI_INT, i, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                printf("Number %d is %s\n", arr[i - 1], (prime_flag ? "Prime" : "Not Prime"));
            }
        }
    } else {
        int num;
        MPI_Recv(&num, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        int result = is_prime(num);
        MPI_Send(&result, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }

    MPI_Finalize();
    return 0;
}
