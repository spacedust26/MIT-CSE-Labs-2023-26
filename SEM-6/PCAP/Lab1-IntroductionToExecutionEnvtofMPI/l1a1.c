//Additional Exercise 1 - Write a program in MPI to reverse the digits of the following integer array of size 9 with 9 processes. Initialze the array to the following values.
// Input array : 18, 523, 301, 1234, 2, 14, 108, 150, 1928
// Output array : 81, 325, 103, 4321, 2, 41, 801, 51, 8291

#include<stdio.h>
#include<mpi.h>

int rev(int n){
    int ans  = 0;
    while(n > 0){
        ans = ans * 10 + (n%10);
        n/=10;
    }
    return ans;
}

int main(int argc, char *argv[]){
    int rank, size;
    int arrin[9] = {18, 523, 301, 1234, 2, 14, 108, 150, 1928};
    int arrout[9];
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    arrout[rank] = rev(arrin[rank]);
    printf("%d -> %d\n", arrin[rank], arrout[rank]);
    MPI_Finalize();
    return 0;
}