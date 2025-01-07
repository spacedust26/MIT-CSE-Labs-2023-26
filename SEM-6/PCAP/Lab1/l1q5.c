#include<stdio.h>
#include<mpi.h>

int factorial(int n){
    int fact = 1;
    while(n > 0){
        fact *= n;
        n--;
    }
    return fact;
}

int fibonacci(int n){
    if(n <= 1) return n;
    else return fibonacci(n-1) + fibonacci(n-2);
}

int main(int argc, char *argv[]){
    int rank, size;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    if(rank % 2){
        int ans = fibonacci(rank);
        printf("Rank %d: Fibonacci value: %d\n", rank, ans);
    }
    else{
        int ans = factorial(rank);
        printf("Rank %d: Factorial value: %d\n", rank, ans);
    }
    MPI_Finalize();
    return 0;
}