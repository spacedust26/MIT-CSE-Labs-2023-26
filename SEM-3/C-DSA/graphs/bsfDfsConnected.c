#include<stdio.h>
#include<stdlib.h>
struct node {
  int data;
  struct node *next;
};
struct graph{
  int vertices;
  struct node **list;
};
struct node *createNode(int data){
  struct node *newnode=(struct node*)malloc(sizeof(struct node));
  newnode->data = data;
  newnode->next=NULL;
  return newnode;
}
struct graph *createGraph(int vertices){
  struct graph *newgraph=(struct graph*)malloc(sizeof(struct graph));
  newgraph->vertices=vertices;
  newgraph->list = (struct node**)malloc(vertices*sizeof(struct node*));
  for(int i=0;i<vertices;i++){
    newgraph->list[i]=NULL;
  }
  return newgraph;
}
void addEdge(struct graph *g, int src, int des){
  struct node *newnode = createNode(des);
  newnode->next = g->list[src];
  g->list[src]= newnode;
  newnode = createNode(src);
  newnode->next = g->list[des];
  g->list[des]= newnode;
}
//BREADTH FIRST SEARCH
void bfs(struct graph *g,int start){
  int *visited=(int *)malloc(g->vertices*sizeof(int));
  for(int i=0;i<g->vertices;i++){
    visited[i]=0;
  }
  int q[g->vertices];
  int front=0,rear=0;
  visited[start]=1;
  q[rear++]=start;
  while(front<rear){
    int current=q[front++];
    printf(" %d ",current);
    struct node *temp=g->list[current];
    while(temp!=NULL){
      int adj=temp->data;
      if(!visited[adj]){
        visited[adj]=1;
        q[rear++]=adj;
      }
      temp=temp->next;
    }
  }
  free(visited);
}
//DEPTH FIRST SEARCH
void dfsrecur(struct graph *g, int vertex, int *visited){
  visited[vertex]=1;
  printf(" %d ",vertex);
  struct node *temp = g->list[vertex];
  while(temp!=NULL){
    int adj=temp->data;
    if(!visited[adj]){
      dfsrecur(g,adj,visited);
    }
    temp = temp->next;
  }
}

void dfs(struct graph *g, int start){
  int *visited=(int *)malloc(g->vertices*sizeof(int));
  for(int i=0;i<g->vertices;i++){
    visited[i]=0;
  }
  dfsrecur(g,start,visited);
  free(visited);
}

//TO FIND CONNECTED COMPONENETS
void connect(struct graph *g){
  int *visited=(int *)malloc(g->vertices*sizeof(int));
  for(int i=0;i<g->vertices;i++){
    visited[i]=0;
  }
  for (int i = 0; i < g->vertices; i++) {
    if (!visited[i]) {
      dfsrecur(g, i, visited);
      printf("\n");
    }
  }
  free(visited);
}
int main(){
  int v,choice,src,des,start;
  printf("Enter vertices: ");
  scanf("%d",&v);
  struct graph *g = createGraph(v);
  do{
    printf("Enter source and destination: ");
    scanf("%d %d",&src,&des);
    addEdge(g,src,des);
    printf("1->continue 0->stop: ");
    scanf("%d",&choice);
  }while(choice);
  printf("Enter start vertex: ");
  scanf("%d",&start);
  printf("\nBreadth first search: ");
  bfs(g,start);
  printf("\nDepth first search: ");
  dfs(g,start);
  printf("\nConnected componenets:");
  connect(g);
}