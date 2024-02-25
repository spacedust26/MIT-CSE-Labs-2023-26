//To find the total number of nodes in a binary tree
//Input - binary tree
//Output - total nodes
//Time complexity - O(n)

#include<stdio.h>
#include<stdlib.h>

int opcount = 0;
struct node{
  int data;
  struct node *left;
  struct node *right;
};

struct node *createnode(int data){
  struct node *newnode = (struct node*)malloc(sizeof(struct node));
  newnode->data = data;
  newnode->left = newnode->right = NULL;
  return newnode;
}

int countnode = 0;
int count(struct node *root){
  opcount++;
  if(root == NULL) return 0;
  count(root->left);
  countnode++;
  count(root->right);
  return countnode;
}

int main(){
  struct node *root;
  root = createnode(1);
  root->left = createnode(2);
  root->right = createnode(3);
  root->left->left = createnode(4);
  root->left->right = createnode(5);
  printf("Total number of nodes: %d\n", count(root));
  printf("Opcount = %d\n",opcount);
}
