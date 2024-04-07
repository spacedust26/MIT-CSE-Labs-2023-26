// Write a program to implement Stack and Queue using circular doubly linked list.
#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node *left;
  struct node *right;
};

struct node *createNode(int data){
  struct node *newnode = (struct node*) malloc(sizeof(struct node));
  newnode->data = data;
  newnode->left = newnode->right = NULL;
  return newnode;
}

struct node *push(struct node *tos, int data){
  struct node *newnode = createNode(data);
  if(tos == NULL){
    tos = newnode;
    newnode->left = newnode->right = tos;
  }
  else{
    struct node *temp = tos;
    while(temp->right != tos){
      temp = temp->right;
    }
    temp->right = newnode;
    tos->left = newnode;
    newnode->right = tos;
    newnode->left = temp;
    tos = newnode;
  }
  return tos;
}

struct node *pop(struct node *tos){
  if(tos == NULL){
    printf("\nEmpty stack.");
  }else{
    struct node *temp = tos;
    while(temp->right != tos){
      temp = temp->right;
    }
    temp->right = tos->right;
    tos->right->left = temp;
    tos = tos->right;
  }
  return tos;
}

void displayStack(struct node *tos){
  struct node *temp = tos;
  while(temp->right != tos){
    printf("%d ",temp->data);
    temp = temp->right;
  }
  printf("%d ",temp->data);
}

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int data){
  struct node *newnode = createNode(data);
  if(front == NULL && rear == NULL){
    front = rear = newnode;
    newnode->left = newnode->right = newnode;
  }else{
    newnode->left = rear;
    rear->right = newnode;
    newnode->right = front;
    front->left = rear->right;
    rear = rear->right;
  }
}

void dequeue(){
  if(front == NULL && rear == NULL){
    printf("\nEmpty queue.");
  }else{
    front = front->right;
    front->left = rear;
    rear->right = front;
  }
}

void displayQueue(){
  struct node *temp = front;
  while(temp != rear){
    printf("%d ",temp->data);
    temp = temp->right;
  }
  printf("%d ",temp->data);
}

int main(){
  int choice,data;
  printf("Stack(1) or a Queue(2)? : ");
  scanf("%d",&choice);
  switch(choice){
    case 1:{
      struct node *tos = NULL;
      int choose = 1;
      int menu;
      while(choose){
        printf("\nStack menu: 1)push 2)pop 3)display 4)exit : ");
        scanf("%d",&menu);
        switch(menu){
          case 1:{
            printf("Enter element to be pushed: ");
            scanf("%d",&data);
            tos = push(tos, data);
            break;
          }
          case 2:{
            tos = pop(tos);
            printf("\nElement popped.");
            break;
          }
          case 3:{
            printf("\nDisplaying stack: ");
            displayStack(tos);
            break;
          }
          default:{
            exit(1);
            break;
          }
        }
      }
      break;
    }
    case 2:{
      int choose = 1;
      int menu;
      while(choose){
        printf("\nQueue menu: 1)enqueue 2)dequeue 3)display 4)exit : ");
        scanf("%d",&menu);
        switch(menu){
          case 1:{
            printf("Enter element to be enqueued: ");
            scanf("%d",&data);
            enqueue(data);
            break;
          }
          case 2:{
            dequeue();
            printf("\nElement dequeued.");
            break;
          }
          case 3:{
            printf("\nDisplaying queue: ");
            displayQueue();
            break;
          }
          default:{
            exit(1);
            break;
          }
        }
      }
      break;
    }
    default:break;
  }
}