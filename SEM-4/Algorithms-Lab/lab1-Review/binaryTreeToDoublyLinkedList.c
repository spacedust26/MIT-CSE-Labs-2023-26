// Write a program to convert a Binary tree to a Doubly linked list
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
struct node *head = NULL;

struct node *ddl(int data){
  struct node *newnode = (struct node*) malloc(sizeof(struct node));
  newnode->data = data;
  newnode->left = newnode-> right = NULL;
  if(head == NULL){
    head = newnode;
  }else{
    struct node *temp = head;
    while(temp->right != NULL){
      temp = temp->right;
    }
    temp->right = newnode;
    newnode->left = temp;
  }
  return head;
}

void inorder(struct node *root){
  if(root == NULL) return;
  inorder(root->left);
  head = ddl(root->data);
  inorder(root->right);
}

void printddl(){
  struct node *temp = head;
  while(temp != NULL){
    printf("%d ",temp->data);
    temp = temp->right;
  }
}

int main(){
  printf("**********Binary tree**********\n");
  struct node *root = NULL;
  root = create();
  printf("**********Doubly linked list*********\n");
  inorder(root);
  printddl();
}