#include<stdio.h>
#include<stdlib.h>
//NODE AND GRAPH
struct node{
  int data;
  struct node *next;
};

struct graph{
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
struct graph *createGraph(int vertices){
  struct graph *newGraph = (struct graph*)malloc(sizeof(struct graph));
  newGraph->vertices = vertices;
  newGraph->list = (struct node**)malloc(vertices * sizeof(struct node*));
  for(int i=0;i<vertices;i++){
    newGraph->list[i]=NULL;
  }
  return newGraph;
}
//ADD EDGE FOR UNDIRECTED GRAPH
void addEdge(struct graph *graph,int src,int des){
  struct node *newnode = createNode(des);
  newnode->next = graph->list[src];
  graph->list[src]= newnode;

  //FOR AN UNDIRECTED GRAPH
  newnode=createNode(src);
  newnode->next = graph->list[des];
  graph->list[des]= newnode;
}

//ADD EDGE FOR DIRECTED GRAPH
// void addEdge(struct graph *graph,int src,int des){
//   struct node *newnode = createNode(des);
//   newnode->next = graph->list[src];
//   graph->list[src]= newnode;
// }

//PRINT NODES
void print(struct graph *graph){
  printf("Displaying:\n");
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
//DEGREE OF A VERTEX
int degree(struct graph *g, int vertex){
  struct node *temp = g->list[vertex];
  int count=0;
  while(temp!=NULL){
    count++;
    temp=temp->next;
  }
  return count;
}

//OUT-DEGREE OF A VERETEX
int outdegree(struct graph *g,int vertex){
  return degree(g,vertex);
}
//IN-DEGREE OF A VERTEX
int indegree(struct graph *g,int vertex){
  int count=0;
  for(int i=0;i<g->vertices;i++){
    struct node *temp = g->list[i];
    while(temp!=NULL){
      if(temp->data==vertex) count++;
      temp=temp->next;
    }
  }
  return count;
}
//NUMBER OF EDGES IN DIRECTED GRAPH
int edgesDirected(struct graph *g){
  int count=0;
  for(int i=0;i<g->vertices;i++){
    count+=degree(g,i);
  }
  return count;
}
//NUMBER OF EDGES IN UNDIRECTED GRAPH
int edgesUNDirected(struct graph *g){
  int count=0;
  for(int i=0;i<g->vertices;i++){
    count+=degree(g,i);
  }
  return count/2;
}
//MAIN
int main(){
  int vertices,choice,src,dest,v;
  printf("Enter vertices: ");
  scanf("%d",&vertices);
  struct graph *graph = createGraph(vertices);
  do{
    printf("Enter source and destination: ");
    scanf("%d %d",&src,&dest);
    addEdge(graph,src,dest);
    printf("1->continue 0->stop: ");
    scanf("%d",&choice);
  }while(choice);
  print(graph);

  //FOR UNDIRECTED GRAPH
  printf("Enter vertex to find degree: ");
  scanf("%d",&v);
  printf("Degree of the vertex %d: %d ",v,degree(graph,v));
  printf("\nNumber of edges: %d ",edgesUNDirected(graph));

  //FOR DIRECTED GRAPH
  // printf("Enter vertex to find out and in degree: ");
  // scanf("%d",&v);
  // printf("Out degree of the vertex %d: %d\n",v,outdegree(graph,v));
  // printf("In degree of the vertex %d: %d\n",v,indegree(graph,v));
  // printf("Number of edges: %d ",edgesDirected(graph));
  return 0;
}