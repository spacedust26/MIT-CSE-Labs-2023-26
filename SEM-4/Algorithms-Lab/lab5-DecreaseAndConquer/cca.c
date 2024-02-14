//To find the closest common ancestor in a binary tree
//Input - n1 and n2 as two nodes
//Output - common ancestor of n1 and n2

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
  int data;
  struct node *left;
  struct node *right;
}node;

node *createnode(int data){
  node *newnode = (node *)malloc(sizeof(node));
  newnode->data = data;
  newnode->left = newnode->right = NULL;
  return newnode;
}

node *findcca(node *root, int n1, int n2){
  if(root == NULL) return NULL;
  if(root->data == n1 || root->data == n2) return root;
  node *leftcca = findcca(root->left, n1, n2);
  node *rightcca = findcca(root->right, n1, n2);
  if(leftcca && rightcca) return root;
  if(leftcca) return leftcca;
  if(rightcca) return rightcca;
}

int main(){
  node *root = createnode(1);
  root->left = createnode(2);
  root->right = createnode(3);
  root->left->left = createnode(4);
  root->left->right = createnode(5);
  root->left->left->left = createnode(6);
  root->left->left->right = createnode(7);
  int n1,n2;
  printf("Enter nodes n1 and n2: ");
  scanf("%d %d",&n1,&n2);
  node *cca =findcca(root, n1, n2);
  if(cca != NULL){
    printf("Closest common ancestor of %d and %d is %d.",n1,n2,cca->data);
  }else{
    printf("One or both nodes are not present in the binary tree.");
    return 0;
  }
}