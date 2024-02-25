//To implement graphs using adjacency list
//Input - total vertices and possible edges
//Output - adjacency list of a graph
//Time complexity - O(|v|+|e|)

#include<stdio.h>
#include<stdlib.h>

//node structure
struct node{
  int data;
  struct node *next;
};

//adjacency list
struct node **list;

//create a node
struct node *createNode(int data){
  struct node *newnode = (struct node*)malloc(sizeof(struct node));
  newnode->data = data;
  newnode->next = NULL;
  return newnode;
}

//initialize adjacency list
void initialize(int vertices){
  list = (struct node **) malloc (vertices * sizeof(struct node*));
  for(int i = 0 ; i < vertices ; i++){
    list[i] = NULL;
  }
}

//add edges
void adjacencyList(struct node **list, int s, int d, int vertices){
  //Undirected graph
  struct node *dest = createNode(d);
  dest->next = list[s];
  list[s] = dest;
  struct node *src = createNode(s);
  src->next = list[d];
  list[d] = src;
}

//printf adjacency list
void print(struct node **list, int vertices){
  for(int i = 0 ; i < vertices ; i++){
    printf("Vertex %d -> ",i);
    struct node *temp = list[i];
    while(temp!=NULL){
      printf("%d ", temp->data);
      temp = temp->next;
    }
    printf("\n");
  }
}

//Main function
int main(){
  int vertices;
  int s,d,choice;
  printf("Enter total vertices: ");
  scanf("%d",&vertices);
  initialize(vertices);
  do{
    printf("Enter source and destination vertices: ");
    scanf("%d %d",&s,&d);
    adjacencyList(list,s,d,vertices);
    printf("1->continue 0->stop: ");
    scanf("%d",&choice);
  }while(choice==1);
  print(list, vertices);
}