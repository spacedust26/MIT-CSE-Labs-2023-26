//TO CREATE A COPY OF TREE AND CHECK FOR EQUALITY
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
//CREATE COPY OF TREE
struct node *copy(struct node *root){
  struct node *newnode = (struct node*)malloc(sizeof(struct node));
  if(root==NULL)return NULL;
  newnode->data = root->data;
  newnode->left = copy(root->left);
  newnode->right = copy(root->right);
  return newnode;
}
//EQUALITY OF BINARY TREES
int equal(struct node *root1, struct node *root2){
  if(root1==NULL && root2==NULL)return 1;
  if(root1==NULL || root2==NULL)return 0;
  if(root1->data != root2->data)return 0;
  return equal(root1->left, root2->left) && equal(root1->right, root2->right);
}
//MAIN FUNCTION
int main(){
    struct node *root1= NULL;
    root1 = create();
    struct node *root2 = NULL;
    root2 = copy(root1);
    if(equal(root1,root2))printf("Equal");
    else printf("Unequal");
    return 0;
}