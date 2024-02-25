//To find the closest common ancestor in a binary tree
//Input - n1 and n2 as two nodes
//Output - common ancestor of n1 and n2

#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node *left;
  struct node *right;
};

struct node *createnode(int data){
  struct node *newnode = (struct node *)malloc(sizeof(struct node));
  newnode->data = data;
  newnode->left = newnode->right = NULL;
  return newnode;
}

//To find closest common ancestor
struct node *findcca(struct node *root,struct node *p,struct node *q){
  if(root == NULL || root == p || root == q) return root;
  struct node *left = findcca(root->left, p, q);
  struct node *right = findcca(root->right, p, q);
  if(left && right) return root;
  return (left == NULL) ? right:left;
}

//Main function
int main(){
  struct node *root = createnode(1);
  root->left = createnode(2);
  root->right = createnode(3);
  root->left->left = createnode(4);
  root->left->right = createnode(5);
  root->left->left->left = createnode(6);
  root->left->left->right = createnode(7); 
  struct node *p = root->left->right;
  struct node *q = root->left->left->left;
  struct node *result = findcca(root,p,q);
  printf("CCA of %d and %d is %d",p->data, q->data, result->data);
}