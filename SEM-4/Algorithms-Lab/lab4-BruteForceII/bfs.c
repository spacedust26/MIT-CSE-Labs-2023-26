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
}

// #include <stdio.h>
// #include <stdlib.h>

// #define MAX_SIZE 100

// // Structure to represent a node in the adjacency list
// struct Node {
//     int vertex;
//     struct Node* next;
// };

// // Structure to represent the adjacency list
// struct Graph {
//     int numVertices;
//     struct Node** adjLists;
// };

// // Function to create a new node
// struct Node* createNode(int v) {
//     struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
//     newNode->vertex = v;
//     newNode->next = NULL;
//     return newNode;
// }

// // Function to create a graph with a given number of vertices
// struct Graph* createGraph(int vertices) {
//     struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
//     graph->numVertices = vertices;
//     graph->adjLists = (struct Node**)malloc(vertices * sizeof(struct Node*));
//     for (int i = 0; i < vertices; i++) {
//         graph->adjLists[i] = NULL;
//     }
//     return graph;
// }

// // Function to add an edge to an undirected graph
// void addEdge(struct Graph* graph, int src, int dest) {
//     // Add an edge from src to dest
//     struct Node* newNode = createNode(dest);
//     newNode->next = graph->adjLists[src];
//     graph->adjLists[src] = newNode;

//     // Add an edge from dest to src (for undirected graph)
//     newNode = createNode(src);
//     newNode->next = graph->adjLists[dest];
//     graph->adjLists[dest] = newNode;
// }

// // Function to perform Breadth-First Search (BFS) traversal
// void BFS(struct Graph* graph, int startVertex) {
//     // Array to keep track of visited vertices
//     int visited[MAX_SIZE] = {0};

//     // Queue for BFS traversal
//     int queue[MAX_SIZE];
//     int front = 0, rear = 0;

//     // Mark the start vertex as visited and enqueue it
//     visited[startVertex] = 1;
//     queue[rear++] = startVertex;

//     // Loop until the queue is empty
//     while (front < rear) {
//         // Dequeue a vertex from the queue
//         int currentVertex = queue[front++];
//         printf("%d ", currentVertex); // Display the vertex

//         // Traverse the adjacency list of the current vertex
//         struct Node* temp = graph->adjLists[currentVertex];
//         while (temp) {
//             int adjVertex = temp->vertex;
//             // If the adjacent vertex has not been visited, mark it as visited and enqueue it
//             if (!visited[adjVertex]) {
//                 visited[adjVertex] = 1;
//                 queue[rear++] = adjVertex;
//             }
//             temp = temp->next;
//         }
//     }
// }

// int main() {
//     int numVertices;
//     printf("Enter the number of vertices: ");
//     scanf("%d", &numVertices);

//     struct Graph* graph = createGraph(numVertices);

//     int numEdges;
//     printf("Enter the number of edges: ");
//     scanf("%d", &numEdges);

//     printf("Enter the edges (source destination):\n");
//     for (int i = 0; i < numEdges; i++) {
//         int src, dest;
//         scanf("%d %d", &src, &dest);
//         addEdge(graph, src, dest);
//     }

//     int startVertex;
//     printf("Enter the starting vertex for BFS traversal: ");
//     scanf("%d", &startVertex);

//     printf("BFS Traversal starting from vertex %d:\n", startVertex);
//     BFS(graph, startVertex);
//     printf("\n");

//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>

// #define MAX_SIZE 100

// // Function to perform Breadth-First Search (BFS) traversal
// void BFS(int graph[MAX_SIZE][MAX_SIZE], int numVertices, int startVertex) {
//     // Array to keep track of visited vertices
//     int visited[MAX_SIZE] = {0};

//     // Queue for BFS traversal
//     int queue[MAX_SIZE];
//     int front = 0, rear = 0;

//     // Mark the start vertex as visited and enqueue it
//     visited[startVertex] = 1;
//     queue[rear++] = startVertex;

//     // Loop until the queue is empty
//     while (front < rear) {
//         // Dequeue a vertex from the queue
//         int currentVertex = queue[front++];
//         printf("%d ", currentVertex); // Display the vertex

//         // Traverse the adjacency matrix of the current vertex
//         for (int i = 0; i < numVertices; i++) {
//             // If there is an edge from the current vertex to vertex i and i has not been visited
//             if (graph[currentVertex][i] && !visited[i]) {
//                 visited[i] = 1; // Mark vertex i as visited
//                 queue[rear++] = i; // Enqueue vertex i
//             }
//         }
//     }
// }

// int main() {
//     int numVertices;
//     printf("Enter the number of vertices: ");
//     scanf("%d", &numVertices);

//     int graph[MAX_SIZE][MAX_SIZE];

//     printf("Enter the adjacency matrix (%d x %d):\n", numVertices, numVertices);
//     for (int i = 0; i < numVertices; i++) {
//         for (int j = 0; j < numVertices; j++) {
//             scanf("%d", &graph[i][j]);
//         }
//     }

//     int startVertex;
//     printf("Enter the starting vertex for BFS traversal: ");
//     scanf("%d", &startVertex);

//     printf("BFS Traversal starting from vertex %d:\n", startVertex);
//     BFS(graph, numVertices, startVertex);
//     printf("\n");

//     return 0;
// }
