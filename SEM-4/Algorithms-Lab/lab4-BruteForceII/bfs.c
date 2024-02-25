//To perform breadth first search using adjacency matrix and adjacency list
//Input - total vertices and respective edges
//Ouput - BFS traversal
//Time complexity - adjacency matrix |V|^2 adjacency list |V| + |E|

//1) Adjacency Matrix
// #include<stdio.h>

// //Global variables
// int am[100][100];
// int visited[100];
// int queue[100];
// int front = 0, rear = 0;

// //Bfs traversal using an adjacency matrix
// void bfsMatrix(int i, int vertices){
//     visited[i] = 1;
//     queue[rear++] = i;
//     while(front < rear){
//       int data = queue[front++];
//       printf("%d ",data);
//       for(int j = 0 ; j < vertices ; j++){
//         if(am[data][j] && !visited[j]){
//           visited[j] = 1;
//           queue[rear++] = j;
//         }
//       }
//     }
// }

// //Main function
// void main(){
//     int vertices, start;
//     printf("Enter total vertices of the graph: ");
//     scanf("%d",&vertices);
//     printf("Enter adjacency matrix: ");
//     for(int i = 0 ; i < vertices ; i++){
//         for(int j = 0 ; j < vertices ; j++){
//             scanf("%d",&am[i][j]);
//         }
//     }
//     for(int i = 0 ; i < vertices ; i++){
//         visited[i] = 0;
//     }
//     printf("Enter start vertex: ");
//     scanf("%d",&start);
//     printf("\nBFS traversal: ");
//     bfsMatrix(start, vertices);    
// }

// 2)Adjacency List
#include<stdio.h>
#include<stdlib.h>

//structure of node
struct node{
    int data;
    struct node *next;
};

struct node **list;
int visited[100];
int queue[100];
int front = 0, rear = 0;

//create node
struct node *createNode(int data){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

//Initialize adjacency list
void initialize(int vertices){
    list = (struct node **) malloc(vertices * sizeof(struct node*));
    for(int i = 0 ; i < vertices ; i++){
        list[i] = NULL;
    }
}
//Add edges
void adjacencyList(int s, int d, int vertices){
    struct node *dest = createNode(d);
    dest->next = list[s];
    list[s] = dest;
}

//Bfs traversal using an adjacency matrix
void bfsMatrix(int i, int vertices){
    visited[i] = 1;
    queue[rear++] = i;
    while(front < rear){
      int data = queue[front++];
      printf("%d ",data);
      struct node *temp = list[data];
      while(temp!=NULL){
        if(!visited[temp->data]){
          visited[temp->data] = 1;
          queue[rear++] = temp->data;
        }
        temp = temp->next;
      }
    }
}

//Main function
int main(){
    int vertices, start;
    printf("Enter total vertices: ");
    scanf("%d",&vertices);
    initialize(vertices);
    int choice,s,d;
    do{
        printf("Enter source and destination of edges: ");
        scanf("%d %d",&s,&d);
        adjacencyList(s,d,vertices);
        printf("1->continue 0->stop: ");
        scanf("%d",&choice);
    }while(choice == 1);
    for(int i = 0 ; i < vertices ; i++){
        visited[i] = 0;
    }
    printf("Enter start vertex: ");
    scanf("%d",&start);
    printf("\nBFS traversal: ");
    bfsMatrix(start, vertices); 
}