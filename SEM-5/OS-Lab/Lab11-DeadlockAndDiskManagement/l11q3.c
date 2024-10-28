#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int reqId;
    int arrtstamp;
    int cyl;
    int add;
    int prid;
} DSA;

void FCFS(DSA requests[], int n, int start) {
    int current_position = start;
    int total_distance = 0;

    printf("\nFCFS Disk Scheduling:\n");
    printf("Move from %d to %d\n", current_position, requests[0].cyl);
    
    for (int i = 0; i < n; i++) {
        int distance = abs(current_position - requests[i].cyl);
        total_distance += distance;
        current_position = requests[i].cyl;
        printf("Move from %d to %d with Seek %d (Request ID: %d, Process ID: %d)\n",
               current_position, requests[i].cyl, distance, requests[i].reqId, requests[i].prid);
    }

    printf("\nTotal Seek Time (FCFS): %d\n", total_distance);
    float avg = (float)total_distance / n;
    printf("Average Seek Time (FCFS): %f\n", avg);
}

void SSTF(DSA requests[], int n, int start) {
    int current_position = start;
    int total_distance = 0;
    int served[n];
    for (int i = 0; i < n; i++) served[i] = 0;

    printf("\nSSTF Disk Scheduling:\n");
    
    for (int count = 0; count < n; count++) {
        int closest_index = -1;
        int closest_distance = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (!served[i]) {
                int distance = abs(current_position - requests[i].cyl);
                if (distance < closest_distance) {
                    closest_distance = distance;
                    closest_index = i;
                }
            }
        }

        if (closest_index != -1) {
            total_distance += closest_distance;
            printf("Move from %d to %d with Seek %d (Request ID: %d, Process ID: %d)\n",
                   current_position, requests[closest_index].cyl, closest_distance, 
                   requests[closest_index].reqId, requests[closest_index].prid);
            current_position = requests[closest_index].cyl;
            served[closest_index] = 1; // Mark as served
        }
    }

    printf("\nTotal Seek Time (SSTF): %d\n", total_distance);
    float avg = (float)total_distance / n;
    printf("Average Seek Time (SSTF): %f\n", avg);
}

int main() {
    int n;
    printf("Enter the number of requests: ");
    scanf("%d", &n);

    DSA *requests = malloc(n * sizeof(DSA));

    for (int i = 0; i < n; i++) {
        printf("Enter details for request %d:\n", i + 1);
        printf("Request ID: ");
        scanf("%d", &requests[i].reqId);
        printf("Arrival Time Stamp: ");
        scanf("%d", &requests[i].arrtstamp);
        printf("Cylinder: ");
        scanf("%d", &requests[i].cyl);
        printf("Address: ");
        scanf("%d", &requests[i].add);
        printf("Process ID: ");
        scanf("%d", &requests[i].prid);
        printf("\n \n");
    }

    int start_position;
    printf("Enter the starting position of the disk head: ");
    scanf("%d", &start_position);

    FCFS(requests, n, start_position);
    SSTF(requests, n, start_position);

    free(requests);
    return 0;
}