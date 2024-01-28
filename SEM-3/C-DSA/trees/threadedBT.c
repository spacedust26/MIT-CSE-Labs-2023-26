//TO IMPLEMENT A THREADED BINARY TREE
#include<stdio.h>
#include<stdlib.h>
struct node{
  int data;
  struct node *left;
  struct node *right;
  int leftThread;
  int rightThread;
};
//CREATE A THREADED BINARY TREE
struct node *createNode(int data){
  struct node *newnode = (struct node*)malloc(sizeof(struct node));
  newnode->data =data;
  newnode->right = newnode->left = NULL;
  newnode->leftThread = newnode->rightThread = 1;
  return newnode;
}

struct node *insert(struct node *root, int data){
  struct node *temp = root;
  struct node *prev=NULL;
  while(temp!=NULL){
    if(data==temp->data){
      printf("Duplicate key");
      return root;
    }
    prev=temp;
    if(data<temp->data){
      if(temp->leftThread==0)temp = temp->left;
      else break;
    }
    else{
      if(temp->rightThread==0)temp = temp->right;
      else break;
    }
  }
  struct node *newnode = createNode(data);
  if(prev==NULL){
    root=newnode;
  }
  else if(data<prev->data){
    newnode->left=prev->left;
    newnode->right = prev;
    prev->leftThread=0;
    prev->left=newnode;
  }
  else{
    newnode->right=prev->right;
    newnode->left = prev;
    prev->rightThread=0;
    prev->right=newnode;
  }
  return root;
}
//INORDER SUCCESSOR
struct node *inorderSuccessor(struct node *ele){
  if(ele->rightThread==1)return ele->right;
  ele = ele->right;
  while(ele->left==0) ele=ele->left;
  return ele;
}
//INORDER TRAVESRAL
void inorder(struct node *root){
  if(root==NULL){
    printf("empty");
    return;
  }
  struct node *temp=root;
  while(temp->leftThread==0)temp=temp->left;
  while(temp!=NULL){
    printf("%d ",temp->data);
    temp= inorderSuccessor(temp);
  }
}
int main(){
  struct node *root = NULL;
  int choice=1,ele;
  do{
    printf("Enter data: ");
    scanf("%d",&ele);
    root=insert(root,ele);
    printf("1->continue 0->stop: ");
    scanf("%d",&choice);
  }while(choice);
  inorder(root);
}