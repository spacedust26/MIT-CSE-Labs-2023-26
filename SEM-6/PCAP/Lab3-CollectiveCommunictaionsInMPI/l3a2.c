// Additional exercise 2 - Write a MPI program using collective communication functions, to replace all even elements of array A to 1 and replace all odd elements to 0 of size N. Display the results array a, count of all even and odd numbers in root process. Assume N is evenly didvisble by number of processes.
// Example:
// Input Array (A) : 1 2 3 4 5 6 7 8 9
// Resultant Array (A) : 0 1 0 1 0 1 0 1 0
// Even (count) = 4
// Odd (count) = 5

#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[]) {
    int rank, size, element, result, even_count = 0, odd_count = 0;
    int A[100], final_result[100];
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    if (rank == 0) {
        printf("Enter %d elements: ", size);
        for (int i = 0; i < size; i++) {
            scanf("%d", &A[i]);
        }
    }
    MPI_Scatter(A, 1, MPI_INT, &element, 1, MPI_INT, 0, MPI_COMM_WORLD);
    result = (element % 2 == 0) ? 1 : 0;
    MPI_Gather(&result, 1, MPI_INT, final_result, 1, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Reduce(&result, &even_count, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
    if (rank == 0) {
        odd_count = size - even_count;
        printf("Resultant Array (A): ");
        for (int i = 0; i < size; i++) {
            printf("%d ", final_result[i]);
        }
        printf("\nEven (count) = %d\n", even_count);
        printf("Odd (count) = %d\n", odd_count);
    }
    MPI_Finalize();
    return 0;
}
