// To perform topological sort of a graph using depth first traversal
//Input - graph
//Ouput - topological sort order
//Time complexity - adjacency matrix O(n^2) adjacency list O(|v| + |e|)

//1)Adjacency matrix
// #include<stdio.h>
// #include<stdlib.h>

// //Global variables
// int am[100][100];
// int visited[100];
// int pop[100];
// int popIndex = 0;
// int isDAG = 1;

// //Dfs traversal using an adjacency matrix
// void dfsMatrix(int i, int vertices){
//     visited[i] = 1;
//     printf("%d ",i);
//     for(int j = 0 ; j < vertices ; j++){
//         if(am[i][j]){
//             if (!visited[j]) {
//                 dfsMatrix(j, vertices);
//             } else if (visited[j] == 1) {
//                 isDAG = 0;
//             }
//         }
//     }
//     visited[i] = 2;
//     pop[popIndex++] = i;
// }

// //Main function
// void main(){
//     int vertices;
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
//     printf("\nDFS traversal: ");
//     for(int i = 0 ; i < vertices ; i++){
//         if(!visited[i]) dfsMatrix(i,vertices);
//     }
//      if(isDAG){
//         printf("The graph is a Directed Acyclic Graph (DAG).\n");
//         printf("\nToplogical sort order: ");
//         for(int i = popIndex -1 ; i >=0 ; i--){
//             printf("%d ",pop[i]);
//         }
//     }else{
//         printf("\nThe graph is not a Directed Acyclic Graph (DAG).\n");
//     }
// }

//2)Adjacency list
#include<stdio.h>
#include<stdlib.h>

//structure of node
struct node{
    int data;
    struct node *next;
};

struct node **list;
int visited[100];
int pop[100];
int popIndex = 0;
int isDAG = 1;

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

void dfsList(int i, int vertices){
    visited[i] = 1;
    printf("%d ",i);
    struct node *temp = list[i];
    while(temp != NULL){
        if(!visited[temp->data]){
            dfsList(temp->data, vertices);
        }else if(visited[temp->data] == 1){
            isDAG = 0;
        }
        temp = temp->next;
    }
    visited[i] = 2;
    pop[popIndex++] = i;
}

//Main function
int main(){
    int vertices;
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
    printf("\nDFS traversal: ");
    for(int i = 0 ; i < vertices ; i++){
        if(!visited[i]) dfsList(i,vertices);
    }
    if(isDAG){
    printf("The graph is a Directed Acyclic Graph (DAG).\n");
    printf("\nToplogical sort order: ");
    for(int i = popIndex -1 ; i >=0 ; i--){
        printf("%d ",pop[i]);
    }
    }else{
        printf("\nThe graph is not a Directed Acyclic Graph (DAG).\n");
    }
}