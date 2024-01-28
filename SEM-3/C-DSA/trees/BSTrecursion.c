//IMPLEMET A RECURSIVE BINARY SEARCH TREE
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
//FUNCTION TO SEARCH FOR A PARTICULAR VALUE USING RECURSIONS
struct node *searchRecursion(struct node *root, int key){
  if(root==NULL) return NULL;
  if(key==root->data)return root;
  if(key<root->data) return searchRecursion(root->left,key);
  else return searchRecursion(root->right,key);
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
    struct node *temp= createNode(min(root->right));;
    root->data = temp->data;
    root->right = delete(root->right,temp->data);
  }
  return root;
}
//INORDER TRAVERSAL TO CHECK
void inorder(struct node *root){
    if(root==NULL)return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}
//MAIN
void main(){
  struct node *root=NULL;
  int choice=1,key;
  do{
    printf("Enter key: ");
    scanf("%d",&key);
    root = insert(root,key);
    printf("1->continue 0->stop: ");
    scanf("%d",&choice);
  }while(choice);
  inorder(root);
  printf("\nEnter key to be deleted: ");
  scanf("%d",&key);
  root = delete(root,key);
  inorder(root);
  printf("Enter element whose inorder successor has to be found: ");
  scanf("%d",&key);
  struct node *temp = createNode(key);
  printf("%d",min(temp));
  printf("\nEnter key to be searched: ");
  scanf("%d",&key);
  if(searchRecursion(root,key))
    printf("Key found\n");
  else printf("Key not found\n");
  printf("Maximum element: %d\n",max(root));
  printf("Minimum elemnent: %d\n",min(root));
  printf("Height: %d",height(root));
}