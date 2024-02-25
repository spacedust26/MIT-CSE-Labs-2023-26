//To find the height of a binary tree
//Input - binary tree
//Output - height
//Time complexity - O(n);

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

struct node *insert(struct node *root, int data){
  if(root == NULL) return createNode(data);
  if(data < root->data){
    root->left = insert(root->left, data);
  }
  else if(data > root->data){
    root->right = insert(root->right, data);
  }
  else{
    printf("\nDuplicate element");
    return root;
  }
  return root;
}

void inorder(struct node *root){
  if(root==NULL) return;
  inorder(root->left);
  printf("%d ",root->data);
  inorder(root->right);
}

int maxnum(int a, int b){
  return a>b?a:b;
}
int height(struct node *root){
  if(root == NULL) return -1;
  else return maxnum(height(root->left), height(root->right)) + 1;
}

int main(){
  int data;
  struct node *root = NULL;
  int choice;
  do{
    printf("Enter data: ");
    scanf("%d",&data);
    root = insert(root, data);
    printf("1->continue 0->stop: ");
    scanf("%d",&choice);
  }while(choice==1);
  inorder(root);
  printf("\nHeight of the tree is %d",height(root));
}