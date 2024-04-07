//To check whether a graph is bipartite using dfs traversal
//Input - total vertices and respective edges
//Ouput - bipartite or not
//Time complexity - adjacency matrix |V|^2 adjacency list |V| + |E|

#include<stdio.h>

int v, am[100][100];
int visited[100];
int color[100];// 0 uncolored, 1 for color A, -1 for color B
int isBipartite = 1;

//check bipartite
void dfs(int i, int vertices){
  visited[i] = 1;
  for(int j = 0 ; j < vertices ; j++){
    if(am[i][j] && !visited[j]){
      color[j] = -color[i]; //opp color of neighbour
      dfs(j,vertices);
    }else if(am[i][j] && color[i] == color[j]){
      isBipartite = 0;
      return;
    }
  }
}

//Main function
int main(){
  printf("Enter total vertices: ");
  scanf("%d",&v);
  printf("Enter adjacenecy matrix: ");
  for(int i = 0 ; i < v ; i++){
    for(int j = 0; j < v; j++){
      scanf("%d",&am[i][j]);
    }
  }
  for(int i = 0 ; i < v ; i++){
    visited[i] = 0;
    color[i] = 0;
  }
  for(int i = 0 ; i < v ; i++){
    if(!visited[i]){
      color[i] = 1;
      dfs(i, v);
    }
  }
  if(isBipartite)printf("\nBipartite");
  else printf("Not bipartite");
}
