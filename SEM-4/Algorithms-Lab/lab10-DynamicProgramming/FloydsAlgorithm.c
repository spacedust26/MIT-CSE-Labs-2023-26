//Program to implement Floyd's algorithm for the All-Pairs- Shortest-Paths problem for any given graph
//Input - weighted graph and total vertices
//Output - distance matrix
//Time complexity - O(n^3)

#include<stdio.h>
#include<stdlib.h>
int opcount = 0;

//Shortest path matrix
void shortestPath(int graph[50][50], int v){
  int sp[50][50];
  for(int i = 0 ; i < v ; i++){
    for(int j = 0 ; j < v ; j++){
      sp[i][j] = graph[i][j];
    }
  }
  for(int k = 0 ; k < v ; k++){
    for(int i = 0 ; i < v ; i++){
      for(int j = 0 ; j < v ; j++){
        opcount++;
        if(sp[i][k] + sp[k][j] < sp[i][j]){
          sp[i][j] = sp[i][k] + sp[k][j];
        }
      }
    }
  }
  printf("\nShortest path matrix:\n");
  for(int i = 0 ; i < v ; i++){
    for(int j = 0 ; j < v ; j++){
      printf("%d ",sp[i][j]);
    }
    printf("\n");
  }
}

//Main function
int main(){
  int v, graph[50][50];
  printf("Enter the number of vertices: ");
  scanf("%d",&v);
  printf("Enter the distance matrix of the diagraph (999 for infinity): ");
  for(int i = 0 ; i < v  ; i++){
    for(int j = 0 ; j < v ; j++){
      scanf("%d",&graph[i][j]);
    }
  }
  shortestPath(graph,v);
  printf("\nOpcount = %d",opcount);
}