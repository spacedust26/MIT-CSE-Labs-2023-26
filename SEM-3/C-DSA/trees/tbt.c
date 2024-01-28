//TO CONSTRUCT A THRAEDED BINARY TREE
#include<stdio.h>
#include<stdlib.h>
struct node{
  int leftThread;
  struct node *left;
  int data;
  struct node *right;
  int rightThread;
};
//CREATE
struct node *createNode(int data){
  struct node *newnode= (struct node*)malloc(sizeof(struct node));
  newnode->data=data;
  newnode->leftThread = newnode->rightThread = 1;
  newnode->left = newnode->right = NULL;
  return newnode;
}
//INSERT
struct node *insert(struct node *root, int data){
  struct node *parent;
  struct node *temp;
  if(root==NULL) return createNode(data);
  else{
    parent=NULL;
    temp=root;
    while(temp!=NULL){
      parent=temp;
      if(data<temp->data){
        if(temp->leftThread==0)temp=temp->left;
        else break;
      }
      else if(data>temp->data){
        if(temp->rightThread==0)temp=temp->right;
        else break;
      }
      else{
        printf("Duplicate");
        return root;
      }
    }
  }
  struct node *newnode=createNode(data);
  if(data<parent->data){
    newnode->left=parent->left;
    newnode->right=parent;
    parent->left=newnode;
    parent->leftThread=0;
  }
  else{
    newnode->right=parent->right;
    newnode->left=parent;
    parent->right=newnode;
    parent->rightThread=0;
  }
  return root;
}

//INORDER TRAVERSAL
struct node *inorderSuccessor(struct node *root){
  if(root==NULL) return NULL;
  if(root->rightThread==1) return root->right;
  root=root->right;
  while(root->leftThread==0){
    root=root->left;
  }
  return root;
}
void inorder(struct node *root){
  if(root==NULL) return ;
  struct node *temp=root;
  while(temp->leftThread==0){
    temp=temp->left;
  }
  while(temp!=NULL){
    printf("%d ",temp->data);
    temp=inorderSuccessor(temp);
  }
}
int main(){
  struct node *root=NULL;
  int choice,data;
  do{
    printf("Enter data: ");
    scanf("%d",&data);
    root=insert(root,data);
    printf("1->continue 0->stop: ");
    scanf("%d",&choice);
  }while(choice);
  printf("\nInorder traversal: ");
  inorder(root);
}