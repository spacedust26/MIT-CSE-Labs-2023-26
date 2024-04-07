//Program to compute the transitive closure of a given directed graph using warshall's algorithm
//Input - adjacency matrix of a directed graph
//Ouput - matrix with 1 -> path exists 0 -> no path
//Time complexity - O(n^3)

#include<stdio.h>
int opcount = 0;

//To compute the transitive closure matrix
void transitiveClosure(int graph[50][50], int v){
  int tcm[50][50];
  for(int i = 0 ; i < v ; i++){
    for(int j = 0 ; j < v ; j++){
      tcm[i][j] = graph[i][j];
    }
  }
  for(int k = 0 ; k < v ; k++){
    for(int i = 0 ; i < v ; i++){
      for(int j = 0 ; j < v ; j++){
        opcount++;
        tcm[i][j] = tcm[i][j] || (tcm[i][k] && tcm[k][j]);
      }
    }
  }
  printf("\nTransitive closure matrix:\n");
  for(int i = 0 ; i < v ; i++){
    for(int j = 0 ; j < v ; j++){
      printf("%d ",tcm[i][j]);
    }
    printf("\n");
  }
}

//Main function
int main(){
  int v, graph[50][50];
  printf("Enter the number of vertices: ");
  scanf("%d",&v);
  printf("Enter the adjacency matrix of the diagraph: ");
  for(int i = 0 ; i < v  ; i++){
    for(int j = 0 ; j < v ; j++){
      scanf("%d",&graph[i][j]);
    }
  }
  transitiveClosure(graph,v);
  printf("\nOpcount = %d",opcount);
}