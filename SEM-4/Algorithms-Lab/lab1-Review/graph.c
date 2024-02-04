//i)Adjacency list
#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node *next;
};

struct graphList{
  int vertices;
  struct node **list;
};
//CREATE NODE AND CREATE GRAPH
struct node *createNode(int data){
  struct node *newnode = (struct node*)malloc(sizeof(struct node));
  newnode->data=data;
  newnode->next = NULL;
  return newnode;
}
struct graphList *createGraph(int vertices){
  struct graphList *graph = (struct graphList*)malloc(sizeof(struct graphList));
  graph->vertices = vertices;
  graph->list = (struct node**)malloc(vertices * sizeof(struct node*));
  for(int i=0;i<vertices;i++){
    graph->list[i]=NULL;
  }
  return graph;
}
//ADD EDGE FOR UNDIRECTED GRAPH
void addEdge(struct graphList *graph,int src,int des){
  struct node *newnode = createNode(des);
  newnode->next = graph->list[src];
  graph->list[src]= newnode;

  //FOR AN UNDIRECTED GRAPH
  newnode=createNode(src);
  newnode->next = graph->list[des];
  graph->list[des]= newnode;
}
//PRINT NODES
void displayList(struct graphList *graph){
  printf("Displaying adjacency list:\n");
  for(int i=0;i<graph->vertices;i++){
    printf("Vertex %d: ",i);
    struct node *temp=graph->list[i];
    while(temp!=NULL){
      printf(" %d ", temp->data);
      temp=temp->next;
    }
    printf("\n");
  }
}


//ii)Adjacency matrix
typedef struct{
  int vertices;
  int matrix[30][30];
}graph;
void initialize(graph *g,int vertices){
  g->vertices = vertices;
  for (int i = 0; i < vertices; i++){
    for(int j=0;j<vertices;j++){
      g->matrix[i][j] = 0;
    }
  }  
}
void addVertex(graph *g, int s, int d){
  if((s>=0 && s<g->vertices) && (d>=0 && d<g->vertices)){
    g->matrix[s][d]=1;
  }else{
    printf("Invalid position\n");
  }
}
void display(graph *g){
  printf("Displaying adjacency matrix:\n");
  for(int i=0;i<g->vertices;i++){
    for(int j=0;j<g->vertices;j++){
      printf(" %d ",g->matrix[i][j]);
    }
    printf("\n");
  }
}
//MAIN
int main(){
  int vertices;
  printf("Enter number of vertices: ");
  scanf("%d",&vertices);
  graph g;
  initialize(&g,vertices);
  int choice;
  printf("Enter choice of representation: 1)Adjacency list 2)Adjacency matrix: ");
  scanf("%d",&choice);
  switch(choice){
    case 1: {
      int choice,src,dest;
      struct graphList *graph = createGraph(vertices);
      do{
        printf("Enter source and destination: ");
        scanf("%d %d",&src,&dest);
        addEdge(graph,src,dest);
        printf("1->continue 0->stop: ");
        scanf("%d",&choice);
      }while(choice);
      displayList(graph);
      break;
    }
    case 2:{
      int flag;
      do{
        int s,d;
        printf("Enter source and destination for edge: ");
        scanf("%d %d",&s,&d);
        addVertex(&g,s,d);
        printf("Enter 1->continue 0->stop: ");
        scanf("%d",&flag);
      }while(flag);
      display(&g);
      break;
    }
    default: break;
  }
}