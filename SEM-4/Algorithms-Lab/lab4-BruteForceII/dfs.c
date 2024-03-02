//Depth-first search of a graph using 1)adjacency matrix and 2)adjacency list
//Input - total vertices and respective edges
//Ouput - DFS traversal , Push and Pop order
//Time complexity - adjacency matrix |V|^2 adjacency list |V| + |E|

//1) Adjacency Matrix
// #include<stdio.h>

// //Global variables
// int am[100][100];
// int visited[100];
// int push[100];
// int pushIndex = 0;
// int pop[100];
// int popIndex = 0;

// //Dfs traversal using an adjacency matrix
// void dfsMatrix(int i, int vertices){
//     visited[i] = 1;
//     push[pushIndex++] = i;
//     printf("%d ",i);
//     for(int j = 0 ; j < vertices ; j++){
//         if(am[i][j] && !visited[j]){
//             dfsMatrix(j,vertices);
//         }
//     }
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
//     printf("\nPush order: ");
//     for(int i = 0 ; i < pushIndex ; i++){
//         printf("%d ",push[i]);
//     }
//     printf("\nPop order: ");
//     for(int i = 0 ; i < popIndex ; i++){
//         printf("%d ",pop[i]);
//     }
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
int push[100];
int pushIndex = 0;
int pop[100];
int popIndex = 0;

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
    struct node *src = createNode(s);
    src->next = list[d];
    list[d] = src;
}

void dfsList(int i, int vertices){
    visited[i] = 1;
    push[pushIndex++] = i;
    printf("%d ",i);
    struct node *temp = list[i];
    while(temp != NULL){
        if(!visited[temp->data]){
            dfsList(temp->data, vertices);
        }
        temp = temp->next;
    }
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
    printf("\nPush order: ");
    for(int i = 0 ; i < pushIndex ; i++){
        printf("%d ",push[i]);
    }
    printf("\nPop order: ");
    for(int i = 0 ; i < popIndex ; i++){
        printf("%d ",pop[i]);
    }
}