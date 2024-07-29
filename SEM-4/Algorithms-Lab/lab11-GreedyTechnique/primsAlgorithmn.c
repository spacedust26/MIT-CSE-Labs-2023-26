//To find the minimum cost spanning tree of a given undirected graph using prim's algorithm
//Input - weighted adjacency matrix and total vertices
//Output - set of edges composing a minimum spanning tree
//Time complexity - O(n^2) for adjacency matrix, O(mlogn) for adjacency list

#include<stdio.h>
#include<limits.h>

//Prims function
void prim(int graph[20][20], int vertices){
  int mst[20], key[20], set[20];
  for(int i = 0; i < vertices ; i++){
    key[i] = INT_MAX;
    set[i] = 0;
  }
  key[0]=0, mst[0]=-1;
  for(int i = 0; i < vertices ; i++){
    int u = minkey(key,set);
  }
}

//main function
int main(){
  int vertices, graph[20][20];
  printf("Enter total vertices: ");
  scanf("%d",&vertices);
  printf("Enter weighted adjacency matrix: ");
  for(int i = 0 ; i < vertices ; i++){
    for(int j = 0; j < vertices ; j++){
      scanf("%d",&graph[i][j]);
    }
  }
  prim(graph, vertices);
}