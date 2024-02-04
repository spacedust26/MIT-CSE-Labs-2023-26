//Assignment problem using brute force technique
//Input - Cost matrix and size
//Output - Lowest cost and job assigmnent
//Time efficency - O(n!)

#include <stdio.h>

#define MAX_N 40

int cost[MAX_N][MAX_N];
int assignment[MAX_N];
int min_assignment[MAX_N];
int used[MAX_N];
int min_cost = 999999;

void permute(int n, int index, int total_cost){
    if (index == n){
        if (total_cost < min_cost){
            min_cost = total_cost;
            for (int i = 0; i < n; i++) {
                min_assignment[i] = assignment[i];
            }
        }
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            used[i] = 1;
            assignment[index] = i;
            permute(n, index + 1, total_cost + cost[index][i]);
            used[i] = 0;
        }
    }
}

int main() {
    int n;
    printf("Enter numbers of jobs to be assigned to the persons ");
    scanf("%d", &n);
    printf("Enter the cost matrix (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }
    permute(n, 0, 0);
    printf("Minimum cost of assignment: %d\n", min_cost);
    printf("Assignments:\n");
    for (int i = 0; i < n; i++) {
        printf("Agent %d -> Task %d\n", i+1, min_assignment[i]+1);
    }
    return 0;
}
