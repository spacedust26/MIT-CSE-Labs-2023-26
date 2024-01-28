//TO IMPLEMENT LEVEL ORDER TRAVERSAL
#include<stdio.h>
#include<stdlib.h>
#define size 50
struct node{
    int data;
    struct node *left;
    struct node *right;
};
//CREATE FUNCTION USING RECURSIVE APPROACH
struct node *create(){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    int x;
    printf("Enter data(-1 for no node): ");
    scanf("%d",&x);
    if(x==-1) return NULL;
    newnode->data = x;
    printf("Left child of %d: ",x);
    newnode->left = create();
    printf("Right child of %d: ",x);
    newnode->right = create();
    return newnode;
}
//QUEUE IMPLMENTATION
typedef struct {
  struct node *a[size];
  int front;
  int rear;
}queue;
void enqueue(queue *q, struct node *ele){
  if(q->front == -1 && q->rear ==-1){
    q->front = q->rear = 0;
    q->a[q->rear] = ele;
  }
  else{
    q->a[++q->rear]=ele;
  }
}
struct node *dequeue(queue *q){
  if(q->front ==-1 && q->rear ==-1){
    printf("Empty queue");
    return NULL;
  } 
  struct node *ele = q->a[q->front]; 
  if(q->front == q->rear){
    q->front = q->rear = -1;
  }
  else{
    q->front++;
  }
  return ele;
}
void levelOrder(struct node *root){
  if(root == NULL) return;
  queue qs;
  queue *q;
  q=&qs;
  q->front = -1;
  q->rear = -1;
  enqueue(q,root);
  while(q->front != -1){
    struct node *temp = dequeue(q);
    printf("%d ",temp->data);
    if(temp->left!=NULL){
      enqueue(q,temp->left);
    }
    if(temp->right!=NULL){
      enqueue(q,temp->right);
    }
  }
}
int main(){
    struct node *root= NULL;
    root = create();
    levelOrder(root);
}