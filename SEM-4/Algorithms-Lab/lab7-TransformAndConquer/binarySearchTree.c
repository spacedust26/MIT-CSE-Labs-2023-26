//To create a binary search tree and display it elements using traversal methods
//Input - keys
//Output - preorder, inorder and postorder traversals
//Time complexity - O(log n)

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

//create function
struct node *insert(struct node *root, int data){
  if(root == NULL) return createNode(data);
  if(data < root->data) root->left = insert(root->left, data);
  else if(data > root->data) root->right = insert(root->right, data);
  else{
    printf("\nDuplicate element entered.");
    return root;
  }
  return root;
}

//inorder traversal
void inorder(struct node *root){
  if(root == NULL) return;
  inorder(root->left);
  printf("%d ",root->data);
  inorder(root->right);
}

//inorder traversal
void preorder(struct node *root){
  if(root == NULL) return;
  printf("%d ",root->data);
  preorder(root->left);
  preorder(root->right);
}

//inorder traversal
void postorder(struct node *root){
  if(root == NULL) return;
  postorder(root->left);
  postorder(root->right);
  printf("%d ",root->data);
}

//Main function
int main(){
  struct node *root = NULL;
  int choice, key;
  do{
    printf("Enter key: ");
    scanf("%d",&key);
    root = insert(root, key);
    printf("1->continue 0->stop: ");
    scanf("%d",&choice);
  }while(choice == 1);

  printf("Preorder traversal: ");
  preorder(root);
  printf("\nInorder traversal: ");
  inorder(root);
  printf("\nPostorder traversal: ");
  postorder(root);
}