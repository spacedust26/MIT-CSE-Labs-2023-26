//TO FIND OUT THE HEIGHT OF A TREE, NUMBER OF NODES AND LEAF NODE IN A TREE
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left;
    struct node *right;
};
//CREATE FUNCTION USING RECURSIVE APPROACH
struct node *create(){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    int x;
    printf("Enter data(-1 for no node): ");
    scanf("%d",&x);
    if(x==-1) return NULL;
    newnode->data = x;
    printf("Left child of %d: ",x);
    newnode->left = create();
    printf("Right child of %d: ",x);
    newnode->right = create();
    return newnode;
}
//HEIGHT OF A BINARY TREE
int max(int a, int b){
  if(a>b)return a;
  else return b;
}
int height(struct node *root){
  if(root==NULL)return 0;
  return max(height(root->left), height(root->right)) + 1;
}
//TOTAL NUMBER OF NODES
int node(struct node *root){
  static int count=0;
  if(root==NULL) return 0;
  node(root->left);
  count++;
  node(root->right);
  return count;
}
//TOTAL NUMBER OF LEAF NODES
int leaf(struct node *root){
  static int count=0;
  if(root==NULL)return 0;
  if(root->left==NULL && root->right == NULL)count++;
  leaf(root->left);
  leaf(root->right);
  return count;
}
//TO PRINT ANCESTORS OF A NODE
int ancestors(struct node *root, int key){
  if(root==NULL)return 0;
  if(root->data==key)return 1;
  if(ancestors(root->left,key)||ancestors(root->right,key)){
    printf("%d ",root->data);
    return 1;
  }
  return 0;
}
//MAIN FUNCTION
int main(){
    struct node *root= NULL;
    root = create();
    printf("Height: %d",height(root));
    printf("\nTotal Nodes: %d",node(root));
    printf("\nTotal leaf Nodes: %d",leaf(root));
    printf("\nEnter target node for printing ancestors: ");
    int ele;
    scanf("%d",&ele);
    printf("\nAncestors: ");
    ancestors(root,ele);
}