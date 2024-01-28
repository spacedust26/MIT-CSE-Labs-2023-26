/*Write a program to construct a binary tree to support the following operations. Assume no duplicate elements while constructing the tree.
i. Given a key, perform a search in the binary tree. If the key is found then display "key found" else insert the key in the binary search tree.
ii. Display the tree using inorder, preorder and post order traversal methods*/

#include<stdio.h>
#include<stdlib.h>
struct node{
  int data;
  struct node *left;
  struct node *right;
};
//INSERT RECURSIVE FUNCTION
struct node *createNode(int data){
  struct node *newnode= (struct node*)malloc(sizeof(struct node));
  newnode->data=data;
  newnode->left = newnode->right=NULL;
  return newnode;
}
struct node *insert(struct node *root, int data){
  if(root==NULL){
    return createNode(data);
  }
  if(data<root->data){
    root->left = insert(root->left,data);
  }
  else if(data>root->data){
    root->right = insert(root->right,data);
  }
  else{
    printf("Duplicate key");
    return root;
  }
  return root;
}
//Search function
struct node *search(struct node *root,int key){
  if(root==NULL) return NULL;
  if(root->data==key) return root;
  if(key<root->data) return search(root->left,key);
  else return search(root->right,key); 
}

//Inorder traversal
void inorder(struct node *root){
  if(root==NULL) return;
  inorder(root->left);
  printf("%d ",root->data);
  inorder(root->right);
}

//Preorder traversal
void preorder(struct node *root){
  if(root==NULL) return;
  printf("%d ",root->data);
  preorder(root->left);
  preorder(root->right);
}

//Postorder traversal
void postorder(struct node *root){
  if(root==NULL) return;
  postorder(root->left);
  postorder(root->right);
  printf("%d ",root->data);
}
//Main function
void main(void){
  struct node *root=NULL;
  int choice=1,key;
  do{
    printf("Enter key: ");
    scanf("%d",&key);
    root = insert(root,key);
    printf("1->continue 0->stop: ");
    scanf("%d",&choice);
  }while(choice);

  //Search
  printf("Enter key to be searched: ");
  scanf("%d",&key);
  struct node *result = search(root, key);
  if (result != NULL) {
      printf("\nKey found");
  } else {
      printf("\nNot found");
  }

  //Inorder traversal
  printf("\nInorder travesral: ");
  inorder(root);
  //Preorder traversal
  printf("\nPreorder travesral: ");
  preorder(root);
  //Postorder traversal
  printf("\nPostorder travesral: ");
  postorder(root);
}