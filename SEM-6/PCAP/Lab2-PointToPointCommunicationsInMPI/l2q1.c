// Write a MPI program using synchronous send. The sender process sends a word to the receiver. The second process receives the word, toggles each letter of the word and sends it back to the first process. Both processes use synchronous send operation

#include<stdio.h>
#include<string.h>
#include<mpi.h>

int main(int argc, char* argv[]){
	int size,rank;
	char str[100];
	MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Status status;

	if(rank == 0){
		printf("Enter string: ");
		scanf("%s",str);
		printf("Process %d: Sending string %s\n", rank, str);
		MPI_Ssend(&str,sizeof(str),MPI_CHAR,1,0,MPI_COMM_WORLD);

		MPI_Recv(&str,sizeof(str),MPI_CHAR,1,1,MPI_COMM_WORLD,&status);
		printf("Process %d: Received string %s\n",rank, str);
	}
	else if(rank == 1){
		MPI_Recv(&str,sizeof(str),MPI_CHAR,0,0,MPI_COMM_WORLD,&status);
		printf("Process %d: Received string %s\n",rank, str);
		for (int i = 0; i <= strlen(str); i++) {
        	if (str[i] >= 'A' && str[i] <= 'Z') str[i] += 32; 
        	else if (str[i] >= 'a' && str[i] <= 'z') str[i] -= 32; 
    	}

    	printf("Process %d: Toggled string %s\n",rank, str);
		printf("Process %d: Sending string %s\n", rank, str);
		MPI_Ssend(&str,sizeof(str),MPI_CHAR,0,1,MPI_COMM_WORLD);
	}
	MPI_Finalize();
}