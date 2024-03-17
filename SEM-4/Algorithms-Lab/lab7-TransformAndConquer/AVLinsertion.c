//To implement AVL trees
//Input - tree elements
//Output - avl tree representation for the nodes
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

//height function
int maximum(int a, int b){
  return a > b ? a : b;
}
int height(struct node *root){
  if(root == NULL) return -1;
  else return maximum(height(root->left), height(root->right)) + 1;
}

//balance factor
int balanceFactor(struct node *root){
  return height(root->left) - height(root->right);
}

//Left rotate function
struct node *leftRotate(struct node *x){
  struct node *y = x->right;
  struct node *t2 = y->left;
  y->left = x;
  x->right = t2;
  return y;
}

//Right rotate function
struct node *rightRotate(struct node *y){
  struct node *x = y->left;
  struct node *t2 = x->right;
  x->right = y;
  y->left = t2;
  return x;
}

//Insert function
struct node *insert(struct node *root, int key){
  if(root == NULL) return createNode(key);
  if(key < root->data) root->left = insert(root->left, key);
  else if(key > root->data) root->right = insert(root->right, key);
  else{
    printf("Duplicate key");
    return root;
  }
  int bfactor = balanceFactor(root);
  //Left rotation
  if(bfactor > 1 && key < root->left->data){
    return rightRotate(root);
  }
  //Right rotation
  if(bfactor < -1 && key > root->right->data){
    return leftRotate(root);
  }
  //Left right rotation
  if(bfactor > 1 && key > root->left->data){
    root->left = leftRotate(root->left);
    return rightRotate(root);
  }
  //Right left rotation
  if(bfactor < -1 && key < root->right->data){
    root->right = rightRotate(root->right);
    return leftRotate(root);
  }
  return root;
}

//inorder function
void inorder(struct node *root){
  if(root == NULL) return;
  inorder(root->left);
  printf("%d ",root->data);
  inorder(root->right);
}

//Main function
int main(){
  struct node *root = NULL;
  int choice = 1, key;
  do{
    printf("Enter key: ");
    scanf("%d",&key);
    root = insert(root,key);
    printf("1->continue 0->stop: ");
    scanf("%d",&choice);
  }while(choice == 1);
  printf("Inorder traversal: ");
  inorder(root);
}