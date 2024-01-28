//TO IMPLEMENT GRAPHS USING ADJACENCY MATRIX
#include<stdio.h>
#include<stdlib.h>
typedef struct{
  int vertex;
  int matrix[30][30];
}graph;
void initialize(graph *g,int v){
  g->vertex = v;
  for (int i = 0; i < v; i++){
    for(int j=0;j<v;j++){
      g->matrix[i][j] = 0;
    }
  }  
}
void addVertex(graph *g, int s, int d){
  if((s>=0 && s<g->vertex) && (d>=0 && d<g->vertex)){
    g->matrix[s][d]=1;
  }else{
    printf("Invalid position\n");
  }
}
void print(graph *g){
  printf("Printing the graph:\n");
  for(int i=0;i<g->vertex;i++){
    for(int j=0;j<g->vertex;j++){
      printf(" %d ",g->matrix[i][j]);
    }
    printf("\n");
  }
}
int main(){
  int v,s,d,choice=1;
  printf("Enter vertex: ");
  scanf("%d",&v);
  graph g;
  initialize(&g,v);
  printf("Add edges to the graph:\n");
  while(choice){
    printf("Enter source and destination: ");
    scanf("%d %d",&s,&d);
    addVertex(&g,s,d);
    printf("1->add 0->stop");
    scanf("%d",&choice);
  }
  print(&g);
}