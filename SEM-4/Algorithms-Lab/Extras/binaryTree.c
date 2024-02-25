//To implement a binary tree

#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node *left;
  struct node *right;
};

struct node *createNode(int data){
  struct node *newnode = (struct node*)malloc(sizeof(struct node));
  newnode->data = data;
  newnode->left = newnode->right = NULL;
  return newnode;
}

//Create a binary tree
struct node *create(){
  int x;
  printf("Enter data (-1 for no data): ");
  scanf("%d",&x);
  if(x == -1) return NULL;
  struct node *newnode = createNode(x);
  printf("Left child of %d: ",x);
  newnode->left = create();
  printf("Right child of %d: ",x);
  newnode->right = create();
  return newnode;
}

//inorder traversal
void inorder(struct node *root){
  if(root == NULL) return;
  inorder(root->left);
  printf("%d ",root->data);
  inorder(root->right);
}

//preorder traversal
void preorder(struct node *root){
  if(root == NULL) return;
  printf("%d ",root->data);
  preorder(root->left);
  preorder(root->right);
}

//postorder traversal
void postorder(struct node *root){
  if(root == NULL) return;
  postorder(root->left);
  postorder(root->right);
  printf("%d ",root->data);
}

//copy tree
struct node *copy(struct node *root){
  struct node *newnode = (struct node*)malloc(sizeof(struct node));
  if(root == NULL) return root;
  newnode->data = root->data;
  newnode->left = copy(root->left);
  newnode->right = copy(root->right);
  return newnode;
}

//tree equality
int equal(struct node *root1, struct node *root2){
  if(root1 == NULL && root2 == NULL) return 1;
  if(root1 == NULL || root2 == NULL) return 0;
  if(root1->data != root2->data) return 0;
  return equal(root1->left, root2->left) && equal(root1->right, root2->right);
}

//height
int maximum(int a, int b){
  return a>b ? a: b;
}

int height(struct node *root){
  if(root == NULL) return -1;
  else return maximum(height(root->left), height(root->right)) + 1;
}

//total nodes
int nodecount = 0;
int totalnodes(struct node *root){
  if(root == NULL) return 0;
  totalnodes(root->left);
  nodecount++;
  totalnodes(root->right);
  return nodecount;
}

//ancestors
int ancestors(struct node *root, int key){
  if(root == NULL) return 0;
  if(root->data == key) return 1;
  if(ancestors(root->left,key) || ancestors(root->right, key)){
    printf("%d ",root->data);
    return 1;
  }
  return 0;
}

//total leaf nodes
int leafnode = 0;
int leafnodes(struct node *root){
  if(root == NULL) return 0;
  if(root->left == NULL && root->right == NULL) leafnode++;
  leafnodes(root->left);
  leafnodes(root->right);
  return leafnode;
}

int main(){
  struct node *root = NULL;
  root = create();
  printf("\nInorder: ");
  inorder(root);
  printf("\nPreorder: ");
  preorder(root);
  printf("\nPostorder: ");
  postorder(root);
  printf("\nCopied tree: ");
  struct node *root1 = copy(root);
  inorder(root1);
  if(equal(root1, root)) printf("\nEqual");
  else printf("\nUnequal");
  printf("\nHeight: %d",height(root));
  printf("\nTotal nodes: %d",totalnodes(root));
  int key;
  printf("\nAncestors: ");
  printf("Enter key: ");
  scanf("%d",&key);
  ancestors(root, key);
  printf("Leaf nodes: %d",  leafnodes(root));
}