//RECURSIVE BINARY TREE
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
//RECURSIVE INORDER TRAVERSALS
void inorder(struct node *root){
    if(root==NULL)return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}
//RECURSIVE PREORDER TRAVERSEL
void preorder(struct node *root){
    if(root==NULL)return;
    printf(" %d ",root->data);
    preorder(root->left);
    preorder(root->right);
}
//RECURSIVE POSTORDER TRAVERSAL
void postorder(struct node *root){
    if(root==NULL)return;
    postorder(root->left);
    postorder(root->right);
    printf(" %d ",root->data);
}
//MAIN FUNCTION
int main(){
    struct node *root= NULL;
    root = create();
    printf("\nRecursive Preorder traversal: ");
    preorder(root);
    printf("\nRecursive Inorder traversal: ");
    inorder(root);
    printf("\nRecursive Postorder traversal: ");
    postorder(root);
}