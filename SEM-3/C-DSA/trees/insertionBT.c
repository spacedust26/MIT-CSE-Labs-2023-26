//TO INSERT A NODE AT POSITION BASED ON STRING INPUT EX: LLR (CANT INSERT IN ALREADY OCCUPIED POSITION)
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
//TO CHECK IF THE ELEMENT HAS BEEN ADDED
void inorder(struct node *root){
    if(root==NULL)return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}
//INSERT FUNCTION
void insert(struct node *root, char *str, int ele){
  struct node *newnode = (struct node*)malloc(sizeof(struct node));
  newnode->data = ele;
  newnode->left = newnode->right = NULL;
  struct node *parent = NULL;
  struct node *temp = root;
  int i=0;
  while(temp!=NULL && str[i]!='\0'){
    parent=temp;
    if(str[i]=='L') temp = temp->left;
    else temp= temp->right;
    i++;
  }
  if(temp!=NULL || str[i]!='\0'){
    printf("Insertion not found");
    free(temp);
    return;
  }
  if(str[i-1]=='L') parent->left = newnode;
  else parent->right = newnode;
}
//MAIN
int main(){
    struct node *root= NULL;
    root = create();
    printf("Inorder traversal of original tree: ");
    inorder(root);
    char str[20];
    int ele;
    printf("Enter string position (Ex: LLR): ");
    scanf("%s",str);
    printf("Enter element to be inserted: ");
    scanf("%d",&ele);
    insert(root,str,ele);
    printf("Inorder traversal of latest tree: ");
    inorder(root);
}