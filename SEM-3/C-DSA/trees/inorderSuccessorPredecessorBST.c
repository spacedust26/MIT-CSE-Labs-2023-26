#include<stdio.h>
#include<stdlib.h>
struct node{
  int data;
  struct node *left;
  struct node *right;
};
//CREATE FUNTION
struct node *createNode(int data){
  struct node *newnode = (struct node *)malloc(sizeof(struct node));
  newnode->data=data;
  newnode->left = newnode->right=NULL;
  return newnode;
}
struct node *create(struct node *root, int data){
  if(root==NULL) return createNode(data);
  if(data<root->data){
    root->left = create(root->left,data);
  }
  else if(data>root->data){
    root->right = create(root->right,data);
  }
  else{
    printf("Duplicates not allowed");
    return root;
  }
  return root;
}
//INORDER SUCCESSOR
struct node *leftmost(struct node *root){
  if(root==NULL) return root;
  while(root->left!=NULL) root=root->left;
  return root;
}
struct node *inorderSuccessor(struct node *root,struct node *target){
  if(target!=NULL && target->right!=NULL){
    return leftmost(target->right);
  }
  struct node *successor=NULL;
  while(root!=NULL){
    if(target->data<root->data){
      successor=root;
      root=root->left;
    }
    else if(target->data>root->data){
      root=root->right;
    }
    else{
      break;
    }
  }
  return successor;
}
//INORDER PREDECESSOR
struct node *rightmost(struct node *root){
  if(root==NULL) return root;
  while(root->right!=NULL){
    root=root->right;
  }
  return root;
}
struct node *inorderPredecessor(struct node *root, struct node *target){
  while(target!=NULL && target->right!=NULL){
    return rightmost(target->right);
  }
  struct node *predecessor = NULL;
  while(root!=NULL){
    if(target->data> root->data){
      predecessor=root;
      root=root->right;
    }
    if(target->data< root->data){
      root=root->left;
    }
    else break;
  }
  return predecessor;
}

// // Function to find the inorder predecessor of a node in a BST
// struct TreeNode* inorderPredecessor(struct TreeNode* root, struct TreeNode* target) {
//     // If the left subtree of the target is not empty, the predecessor is the rightmost node in that subtree
//     if (target != NULL && target->left != NULL) {
//         return findRightmost(target->left);
//     }

//     // If the left subtree is empty, backtrack to find the ancestor
//     // for which the target is in the right subtree
//     struct TreeNode* predecessor = NULL;
//     while (root != NULL) {
//         if (target->key > root->key) {
//             predecessor = root;
//             root = root->right;
//         } else if (target->key < root->key) {
//             root = root->left;
//         } else {
//             // If the target is found, break the loop
//             break;
//         }
//     }

//     return predecessor;
// }

int main(){
  struct node *root=NULL;
  int choice=1,data;
  do{
    printf("Enter key: ");
    scanf("%d",&data);
    root= create(root,data);
    printf("1->continue 0->stop: ");
    scanf("%d",&choice);
  }while(choice);
  printf("Enter key for inorder successor: ");
  scanf("%d",&data);
  struct node *target = createNode(data);
  struct node *successor= inorderSuccessor(root,target);
  printf("Inorder sucessor of %d is %d ",data,successor->data);
  printf("Enter key for inorder predecessor: ");
  scanf("%d",&data);
  target = createNode(data);
  struct node *predecessor= inorderPredecessor(root,target);
  printf("Inorder predecessor of %d is %d ",data,predecessor->data);
}