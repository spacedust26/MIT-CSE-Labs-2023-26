// 1. Consider the following snapshot of the system. Write C program to implement Banker’s 
// algorithm for deadlock avoidance. The program has to accept all inputs from the user. 
// Assume the total number of instances of A,B and C are 10,5 and 7 respectively. 
// (a)  
// (b)  
// What is the content of the matrix Need? 
// Is the system in a safe state? 
// (c)  
// If a request from process P1 arrives for (1, 0, 2), can the request be granted 
// immediately? Display the updated Allocation, Need and Available matrices.  
// (d)  
// If a request from process P4 arrives for (3, 3, 0), can the request be granted 
// immediately? 
// (e)  
// If a request from process P0 arrives for (0, 2, 0), can the request be granted 
// immediately? 

#include <stdio.h>
#include <pthread.h>
#include <stdbool.h>

#define maxres 15
#define res 3

int alloc[maxres][res];
int max[maxres][res];
int need[maxres][res];
int avl[res];

void calculateNeed(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < res; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }
}

bool isSafe(int n) {
    bool finish[maxres] = {false};
    int work[res];
    for (int i = 0; i < res; i++) {
        work[i] = avl[i];
    }

    int safeseq[maxres];
    int count = 0;

    while (count < n) {
        bool found = false;
        for (int p = 0; p < n; p++) {
            if (!finish[p]) {
                bool canalloc = true;
                for (int j = 0; j < res; j++) {
                    if (need[p][j] > work[j]) {
                        canalloc = false;
                        break;
                    }
                }
                if (canalloc) {
                    for (int j = 0; j < res; j++) {
                        work[j] += alloc[p][j];
                    }
                    safeseq[count++] = p;
                    finish[p] = true;
                    found = true;
                }
            }
        }
        if (!found) {
            printf("System is not in a safe state.\n");
            return false;
        }
    }
    printf("System is in a safe state.\nSafe sequence is: ");
    for (int i = 0; i < n; i++) {
        printf("P%d ", safeseq[i]);
    }
    printf("\n");
    return true;
}

void displayGraphs(int n) {
    printf("Available res: ");
    for (int i = 0; i < res; i++) {
        printf("%d ", avl[i]);
    }
    printf("\n");

    printf("Allocation Matrix:\n");
    printf("    A  B  C\n");
    for (int i = 0; i < n; i++) {
        printf("P%d: ", i);
        for (int j = 0; j < res; j++) {
            printf("%d  ", alloc[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    printf("Max Matrix:\n");
    printf("    A  B  C\n");
    for (int i = 0; i < n; i++) {
        printf("P%d: ", i);
        for (int j = 0; j < res; j++) {
            printf("%d  ", max[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    printf("Need Matrix:\n");
    printf("    A  B  C\n");
    for (int i = 0; i < n; i++) {
        printf("P%d: ", i);
        for (int j = 0; j < res; j++) {
            printf("%d  ", need[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

bool requestResources(int processId, int request[], int n) {
    // Check if the request can be granted
    for (int j = 0; j < res; j++) {
        if (request[j] > need[processId][j]) {
            printf("Error: Process has exceeded its maximum claim.\n");
            return false;
        }
        if (request[j] > avl[j]) {
            printf("Resources not available.\n");
            return false;
        }
    }

    // Simulate allocation
    for (int j = 0; j < res; j++) {
        avl[j] -= request[j];
        alloc[processId][j] += request[j];
        need[processId][j] -= request[j];
    }

    // Check if the system is in a safe state after allocation
    if (isSafe(n)) {
        printf("Resources allocated successfully.\n");
        return true;
    } else {
        // Rollback if not safe
        for (int j = 0; j < res; j++) {
            avl[j] += request[j];
            alloc[processId][j] -= request[j];
            need[processId][j] += request[j];
        }
        printf("Allocation would result in an unsafe state. Rollback performed.\n");
        return false;
    }
}

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter maximum need of all processes (format: A B C for each process):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < res; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    printf("Enter allocation of all processes (format: A B C for each process):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < res; j++) {
            scanf("%d", &alloc[i][j]);
        }
    }

    printf("Enter available res (format: A B C):\n");
    for (int i = 0; i < res; i++) {
        scanf("%d", &avl[i]);
    }

    calculateNeed(n);
    isSafe(n);
    printf("\n\n");
    displayGraphs(n);

    int processId, request[res];
    printf("Enter process ID to request resources (0 to %d): ", n - 1);
    scanf("%d", &processId);
    printf("Enter request for resources (format: A B C): ");
    for (int i = 0; i < res; i++) {
        scanf("%d", &request[i]);
    }

    requestResources(processId, request, n);
    printf("\nUpdated Allocation Matrix:\n");
    displayGraphs(n);

    return 0;
}