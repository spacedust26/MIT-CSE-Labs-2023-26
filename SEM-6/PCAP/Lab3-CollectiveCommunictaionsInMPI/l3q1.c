#include<stdio.h>
#include "mpi.h"

int factorial(int n){
    int f = 1;
    while(n != 0){
        f = f * n;
        n--;
    }
    return f;
}

int main(int argc, char *argv[]){
    int rank, size, n, a[10], b[10],c;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if(rank == 0){
        n = size;
        printf("Enter %d values in the array: ", size);
        for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    }

    MPI_Scatter(a,1,MPI_INT,&c,1,MPI_INT,0,MPI_COMM_WORLD);
    printf("Process %d: Received number %d\n", rank, c);
    c = factorial(c);
    MPI_Gather(&c,1,MPI_INT,b,1,MPI_INT,0,MPI_COMM_WORLD);

    if(rank == 0){
        int sum = 0;
        printf("Result gathered in the root is: \n");
        for(int i =0 ; i <n; i++) {
            printf("Factorial : %d\n", b[i]);
            sum += b[i];
        }
        printf("The sum of N factorials is %d\n", sum);
    }

    MPI_Finalize();
    return 0;
}