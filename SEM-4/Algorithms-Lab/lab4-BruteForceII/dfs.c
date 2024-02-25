//Depth-first search of a graph using adjacency matrix and adjacency list
//Input - total vertices and respective edges
//Ouput - DFS traversal , Push and Pop order
//Time complexity - adjacency matrix |V|^2 adjacency list |V| + |E|

// 1) Adjacency Matrix
#include<stdio.h>

//Global variables
int am[100][100];
int visited[100];

//Dfs traversal using an adjacency matrix
void dfsMatrix(int vertices){

}

//Main function
int main(){
    int vertices;
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
    }
}

































// #include <stdio.h>

// #define MAX_SIZE 100

// int graph[MAX_SIZE][MAX_SIZE];
// int visited[MAX_SIZE];
// int push_order[MAX_SIZE];
// int pop_order[MAX_SIZE];
// int push_index = 0;
// int pop_index = 0;

// void DFS(int vertex, int n) {
//     visited[vertex] = 1;
//     push_order[push_index++] = vertex; // Record push order

//     printf("%d ", vertex); // Display vertex during DFS traversal

//     for (int i = 0; i < n; i++) {
//         if (graph[vertex][i] && !visited[i]) {
//             DFS(i, n);
//         }
//     }

//     pop_order[pop_index++] = vertex; // Record pop order
// }

// int main() {
//     int n;
//     printf("Enter the number of vertices: ");
//     scanf("%d", &n);

//     printf("Enter the adjacency matrix:\n");
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             scanf("%d", &graph[i][j]);
//         }
//     }

//     // Initialize visited array
//     for (int i = 0; i < n; i++) {
//         visited[i] = 0;
//     }

//     // Perform DFS traversal from each vertex
//     printf("DFS Traversal:\n");
//     for (int i = 0; i < n; i++) {
//         if (!visited[i]) {
//             DFS(i, n);
//         }
//     }
//     printf("\n");

//     printf("Push order of vertices during DFS:\n");
//     for (int i = 0; i < push_index; i++) {
//         printf("%d ", push_order[i]);
//     }
//     printf("\n");

//     printf("Pop order of vertices during DFS:\n");
//     for (int i = 0; i < pop_index; i++) {
//         printf("%d ", pop_order[i]);
//     }
//     printf("\n");

//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>

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

// // Depth-first search traversal
// void DFS(struct Graph* graph, int vertex, int* visited, int* push_order, int* pop_order, int* push_index, int* pop_index) {
//     visited[vertex] = 1;
//     push_order[(*push_index)++] = vertex; // Record push order
//     printf("%d ", vertex); // Display vertex during DFS traversal

//     struct Node* adjList = graph->adjLists[vertex];
//     struct Node* temp = adjList;
//     while (temp) {
//         int connectedVertex = temp->vertex;
//         if (!visited[connectedVertex]) {
//             DFS(graph, connectedVertex, visited, push_order, pop_order, push_index, pop_index);
//         }
//         temp = temp->next;
//     }

//     pop_order[(*pop_index)++] = vertex; // Record pop order
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

//     // Initialize visited array
//     int visited[numVertices];
//     for (int i = 0; i < numVertices; i++) {
//         visited[i] = 0;
//     }

//     // Arrays to store push and pop order
//     int push_order[numVertices], pop_order[numVertices];
//     int push_index = 0, pop_index = 0;

//     // Perform DFS traversal from each vertex
//     printf("DFS Traversal:\n");
//     for (int i = 0; i < numVertices; i++) {
//         if (!visited[i]) {
//             DFS(graph, i, visited, push_order, pop_order, &push_index, &pop_index);
//         }
//     }
//     printf("\n");

//     printf("Push order of vertices during DFS:\n");
//     for (int i = 0; i < push_index; i++) {
//         printf("%d ", push_order[i]);
//     }
//     printf("\n");

//     printf("Pop order of vertices during DFS:\n");
//     for (int i = 0; i < pop_index; i++) {
//         printf("%d ", pop_order[i]);
//     }
//     printf("\n");

//     return 0;
// }


// //Depth first search
// #include<stdio.h>
// #include<stdlib.h>
// struct node {
//   int data;
//   struct node *next;
// };
// struct graph{
//   int vertices;
//   struct node **list;
// };
// struct node *createNode(int data){
//   struct node *newnode=(struct node*)malloc(sizeof(struct node));
//   newnode->data = data;
//   newnode->next=NULL;
//   return newnode;
// }
// struct graph *createGraph(int vertices){
//   struct graph *newgraph=(struct graph*)malloc(sizeof(struct graph));
//   newgraph->vertices=vertices;
//   newgraph->list = (struct node**)malloc(vertices*sizeof(struct node*));
//   for(int i=0;i<vertices;i++){
//     newgraph->list[i]=NULL;
//   }
//   return newgraph;
// }
// void addEdge(struct graph *g, int src, int des){
//   struct node *newnode = createNode(des);
//   newnode->next = g->list[src];
//   g->list[src]= newnode;
//   newnode = createNode(src);
//   newnode->next = g->list[des];
//   g->list[des]= newnode;
// }
// //DEPTH FIRST SEARCH
// void dfsrecur(struct graph *g, int vertex, int *visited){
//   visited[vertex]=1;
//   printf(" %d ",vertex);
//   struct node *temp = g->list[vertex];
//   while(temp!=NULL){
//     int adj=temp->data;
//     if(!visited[adj]){
//       dfsrecur(g,adj,visited);
//     }
//     temp = temp->next;
//   }
// }

// void dfs(struct graph *g, int start){
//   int *visited=(int *)malloc(g->vertices*sizeof(int));
//   for(int i=0;i<g->vertices;i++){
//     visited[i]=0;
//   }
//   dfsrecur(g,start,visited);
//   free(visited);
// }
// int main(){
//   int v,choice,src,des,start;
//   printf("Enter vertices: ");
//   scanf("%d",&v);
//   struct graph *g = createGraph(v);
//   do{
//     printf("Enter source and destination: ");
//     scanf("%d %d",&src,&des);
//     addEdge(g,src,des);
//     printf("1->continue 0->stop: ");
//     scanf("%d",&choice);
//   }while(choice);
//   printf("Enter start vertex: ");
//   scanf("%d",&start);
//   printf("\nDepth first search: ");
//   dfs(g,start);
// }