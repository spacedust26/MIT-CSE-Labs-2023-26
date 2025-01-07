//Write a program in MPI to stimulate simple calculator. Perform each operation using different process in parallel.

#include<stdio.h>
#include<mpi.h>

int main(int argc, char *argv[]){
    int rank, size;
    // printf("Enter first number: ");
    // scanf("%d", &a);
    // printf("Enter second number: ");
    // scanf("%d", &b);
    int a = 48, b = 13;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    if(rank == 0){
        int ans = a + b;
        printf("Rank %d performs Addition: Sum is %d\n", rank, ans);
    }
    else if(rank == 1){
        int ans = a - b;
        printf("Rank %d performs Subtraction: Difference is %d\n", rank, ans);
    }
    else if(rank == 2){
        int ans = a * b;
        printf("Rank %d performs Multiplication: Product is %d\n", rank, ans);
    }
    else if(rank == 3){
        float ans = (float) a / (float) b;
        printf("Rank %d performs Division: Quotient is %f\n", rank, ans);
    }
    MPI_Finalize();
    return 0;
}