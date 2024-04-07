//To check whether a graph is bipartite using dfs traversal
//Input - total vertices and respective edges
//Ouput - bipartite or not
//Time complexity - adjacency matrix |V|^2 adjacency list |V| + |E|

#include<stdio.h>

//Global variables
int am[100][100];
int visited[100];
int queue[100];
int front = 0, rear = 0;
int color[100];
int isBipartite = 1;

//Bfs traversal using an adjacency matrix
void bfsMatrix(int i, int vertices){
    visited[i] = 1;
    color[i] = 1;
    queue[rear++] = i;
    while(front < rear){
      int data = queue[front++];
      for(int j = 0 ; j < vertices ; j++){
        if(am[data][j] && !visited[j]){
          visited[j] = 1;
          color[j] = -color[data];
          queue[rear++] = j;
        }else if(am[data][j] && color[data] == color[j]){
          isBipartite = 0;
          return;
        }
      }
    }
}

//Main function
void main(){
    int vertices, start;
    printf("Enter total vertices of the graph: ");
    scanf("%d",&vertices);
    printf("Enter adjacency matrix: ");
    for(int i = 0 ; i < vertices ; i++){
        for(int j = 0 ; j < vertices ; j++){
            scanf("%d",&am[i][j]);
        }
    }
    for(int i = 0 ; i < vertices ; i++){
        visited[i] = 0;
        color[i] = 0;
    }
    printf("Enter start vertex: ");
    scanf("%d",&start);
    bfsMatrix(start, vertices);      
    if(isBipartite)printf("\nBipartite");
    else printf("\nNot bipartite");
}