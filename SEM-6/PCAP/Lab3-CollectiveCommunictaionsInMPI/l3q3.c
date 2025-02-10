// Lab exercise 3 - Write a MPI program to read a string. Use N processes (string length is evenly divisible by N). Find the number of non-vowels in the string. In root process print number of non-vowels found by each process and print the total number of non-vowels

#include<stdio.h>
#include<mpi.h>
#include<unistd.h>
#include<string.h>

int main(int argc, char *argv[]){
	int rank, size, N, M, total_vowels = 0;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	N = size;
	char string[100];
	int process_vowels[N];

	if(rank==0){
        printf("Enter string : ");
        scanf("%[^\n]c", string);
        M = strlen(string) / N;
    }

    MPI_Bcast(&M, 1, MPI_INT, 0, MPI_COMM_WORLD);
    printf("Process %d received M = %d\n", rank, M);
    char rcvbuf[M];
    int num_vowels = 0;
    char vowels[10] = {'a', 'e', 'i', 'o', 'u','A', 'E', 'I', 'O', 'U'};

    MPI_Scatter(string, M, MPI_CHAR, rcvbuf, M, MPI_CHAR, 0, MPI_COMM_WORLD);
    int flag = 1;
    for (int i=0;i<M;i++){
    	for (int j=0;j<10;j++){
    		if (rcvbuf[i] == vowels[j])
    			flag = 0;
    	}
    	if (flag==1) num_vowels++;
    	flag=1;
    }

    MPI_Gather(&num_vowels, 1, MPI_INT, &process_vowels, 1, MPI_INT, 0, MPI_COMM_WORLD);

    if (rank==0){
    	sleep(1);
    	printf("Gathered data: \n");
    	for (int i=0;i<N;i++){
    		printf("%d\n", process_vowels[i]);
    		total_vowels +=process_vowels[i];
    	}
    	printf("Total non-vowels count: %d\n", total_vowels);
    }

    MPI_Finalize();
    return 0;
}