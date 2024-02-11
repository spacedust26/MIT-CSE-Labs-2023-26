//Progarm to perform topological sort
//Techniques used - depth first technique, source removal technique

#include <stdio.h>
#define MAX_SIZE 100

//Global variables
int graph[MAX_SIZE][MAX_SIZE];
int visited[MAX_SIZE];
int push_order[MAX_SIZE];
int pop_order[MAX_SIZE];
int push_index = 0;
int pop_index = 0;
int topological_order[MAX_SIZE];


void DFS(int vertex, int n) {
    visited[vertex] = 1;
    push_order[push_index++] = vertex;
    for (int i = 0; i < n; i++) {
        if (graph[vertex][i] && !visited[i]) {
            DFS(i, n);
        }
    }
    pop_order[pop_index++] = vertex;
}

int main() {
    int n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            DFS(i, n);
        }
    }
    printf("\nTopological sort using Depth-First search:\n");
    for (int i = pop_index -1 ; i >= 0 ; i--) {
        printf("%d ", pop_order[i]);
    }
    printf("\n");


    return 0;
}