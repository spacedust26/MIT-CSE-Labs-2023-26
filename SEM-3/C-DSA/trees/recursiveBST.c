//RECURSIVE BINARY SEARCH TREE
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left;
    struct node *right;
};
//CREATE A BINARY SEARCH TREE
struct node *createNode(int ele){
  struct node *newnode = (struct node*)malloc(sizeof(struct node));
  newnode->data = ele;
  newnode->left = newnode->right = NULL;
  return newnode;
}
struct node *insert(struct node **root, int ele){
  if(*root==NULL){
    *root=createNode(ele);
  }
  else{
    if(ele<(*root)->data) 
      (*root)->left = insert(&(*root)->left,ele);
    else if(ele>(*root)->data) 
      (*root)->right = insert(&(*root)->right , ele);
    else
      printf("Duplicates not allowed\n");
  }
  return *root;
}
//INORDER TRAVERSAL TO CHECK
void inorder(struct node *root){
    if(root==NULL)return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}
//FUNCTION TO SEARCH FOR A PARTICULAR VALUE USING RECURSIONS
struct node *searchRecursion(struct node *root, int key){
  if(root==NULL) return NULL;
  if(key==root->data)return root;
  if(key<root->data) return searchRecursion(root->left,key);
  else return searchRecursion(root->right,key);
}
//FUNCTION TO SEARCH FOR A PARTICULAR VALUE USING ITERATION
struct node *searchIteration(struct node *root, int key){
    while (root != NULL) {
        if (key == root->data) return root;
        else if (key < root->data)root = root->left;
        else root = root->right;
      }
    return NULL;
}
//MAXIMUM ELEMENT
int max(struct node *root){
  if(root==NULL)return -1;
  while(root->right!=NULL) root=root->right;
  return root->data;
}
//MINIMUM ELEMENT
int min(struct node *root){
  if(root==NULL)return -1;
  while(root->left!=NULL) root=root->left;
  return root->data;
}
//HEIGHT OF A BINARY SEARCH TREE
int maxElement(int a, int b){
  if(a>b)return a;
  else return b;
}
int height(struct node *root){
  if(root==NULL)return 0;
  return maxElement(height(root->left),height(root->right))+1;
}
//DELETE( LEAF NODE , ONE CHILD OR TWO CHILD (INORDER PREDECESSOR OR INORDER SUCCESSOR))
struct node *delete(struct node *root,int key){
  if(root==NULL)return NULL;
  if(key<root->data)  
    root->left = delete(root->left,key);
  else if(key>root->data)  
    root->right = delete(root->right,key);
  else{
    if(root->left==NULL){
      struct node *temp = root->right;
      free(root);
      return temp;
    }
    else if(root->right==NULL){
      struct node *temp = root->left;
      free(root);
      return temp;
    }
    //INOREDER SUCCESSOR
    struct node *minimum=createNode(min(root->right));
    struct node *temp=minimum;
    root->data = temp->data;
    root->right = delete(root->right,temp->data);
  }
  return root;
}
//MAIN
int main(){
  struct node *root= NULL;
  int choice=1,ele;
  do{
    printf("Enter key: ");
    scanf("%d",&ele);
    insert(&root,ele);
    printf("1->continue 0->stop: ");
    scanf("%d",&choice);
  }while(choice);
  inorder(root);
  printf("\nEnter key to be searched: ");
  scanf("%d",&ele);
  if(searchRecursion(root,ele))
    printf("Key found\n");
  else printf("Key not found\n");
  if(searchIteration(root,ele))
    printf("Key found\n");
  else printf("Key not found\n");
  printf("Maximum element: %d\n",max(root));
  printf("Minimum elemnent: %d\n",min(root));
  printf("Height: %d",height(root));
  printf("\nEnter key to be deleted: ");
  scanf("%d",&ele);
  root = delete(root,ele);
  inorder(root);
}