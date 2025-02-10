// Additional exercise 3 - Implement atleast 2 programs to identify deadlock condiitons in synchronous send and standard send with multiple point to pint communications between two processes

#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[]) {
    int rank, size, data;
    
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    data = rank; // Each process sets data as its rank

    if (rank == 0) {
        // Process 0 sends to Process 1 and waits for a response
        MPI_Ssend(&data, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
        MPI_Ssend(&data, 1, MPI_INT, 1, 1, MPI_COMM_WORLD);
    } else if (rank == 1) {
        // Process 1 sends to Process 0 and waits for a response
        MPI_Ssend(&data, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
        MPI_Ssend(&data, 1, MPI_INT, 0, 1, MPI_COMM_WORLD);
    }

    MPI_Finalize();
    return 0;
}
