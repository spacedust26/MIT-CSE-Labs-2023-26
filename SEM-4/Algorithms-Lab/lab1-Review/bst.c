//***** LAB EXRECISE 1 *****
//Binary search tree with no duplicate elements
// i.  Given a key, perform a search in the binary search tree. If the key is found then display “key found” else insert the key in the binary search tree. 
//ii. Display the tree using inorder, preorder and post order traversal methods

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

//Create a binary search tree - recursion
struct node *createBSTrecusion(struct node *root, int key){
  if(root == NULL) return createNode(key);
  if(key < root->data){
    root->left = createBSTrecusion(root->left, key);
  }
  else if(key > root->data){
    root->right =  createBSTrecusion(root->right, key);
  }
  else{
    printf("Duplicate element");
  }
  return root;
}

//Create binary search tree using iteration
struct node *createBSTiteration(struct node *root, int key){
  struct node *newnode = createNode(key);
  if(root == NULL){
    root = newnode;
  }
  else{
    struct node *parent = NULL;
    struct node *temp = root;
    while(temp!= NULL){
      parent = temp;
      if(key < temp->data){
        temp = temp->left;
      }
      else if(key > temp->data){
        temp = temp->right;
      }
      else{
        printf("\nDuplicate element");
      }
    }
    if(key < parent->data) parent->left = newnode;
    else{
      parent->right = newnode;
    }
  }
  return root;
}

//Search key - recursive
struct node *searchRecursive(struct node *root, int key){
  if(root == NULL) return NULL;
  if(root->data == key) return root;
  if(key < root->data) return searchRecursive(root->left, key);
  else return searchRecursive(root->right, key);
}

//Search key - iterative
struct node *searchIterative(struct node *root, int key){
  while(root!= NULL){
    if(key == root->data) return root;
    else if(key < root->data) root = root->left;
    else root= root->right;
  }
  return NULL;
}

//Inorder traversal - recursion
void inorderRecur(struct node *root){
  if(root == NULL) return;
  inorderRecur(root->left);
  printf("%d ",root->data);
  inorderRecur(root->right);
}

//Inorder traversal - iterative
void inorderIterative(struct node *root){
  if(root == NULL){
    printf("Empty tree");
    return;
  }
  struct node *temp = root;
  int flag =1;
  struct node *stack[40];
  int top = -1;
  while(flag){
    while(temp!=NULL){
      stack[++top] = temp;
      temp = temp->left;
    }
    if(top != -1){
      temp = stack[top--];
      printf("%d ",temp->data);
      temp = temp->right;
    }
    else{
      flag = 0;
    }
  }
}

//Preorder traversal - recursion
void preorderRecur(struct node *root){
  if(root == NULL) return;
  printf("%d ",root->data);
  preorderRecur(root->left);
  preorderRecur(root->right);
}

//Preorder traversal - iterative
void preorderIterative(struct node *root){
  struct node *stack[40];
  struct node *temp;
  int top = -1;
  if(root == NULL){
    printf("Empty tree");
    return;
  }
  stack[++top]= root;
  while(top != -1){
    temp = stack[top--];
    printf("%d ",temp->data);
    if(temp->right != NULL) stack[++top] = temp->right;
    if(temp->left != NULL) stack[++top] = temp->left;
  }
}

//Postorder traversal - recursion
void postorderRecur(struct node *root){
  if(root == NULL) return;
  postorderRecur(root->left);
  postorderRecur(root->right);
  printf("%d ",root->data);
}

//Postorder traversal - iterative
void postorderIterative(struct node *root){
  struct stack{
    struct node *node;
    int flag;
  };
  struct stack s[40];
  int top = -1;
  if(root== NULL){
    printf("Empty tree");
    return;
  }
  struct node *temp = root;
  while(1){
    while(temp!=NULL){
      s[++top].node = temp;
      s[top].flag = 1;
      temp = temp->left;
    }
    while(s[top].flag < 0){
      temp = s[top--].node;
      printf("%d ",temp->data);
      if(top == -1) return;
    }
    temp = s[top].node;
    temp = temp->right;
    s[top].flag = -1;
  }
}

//Main function
int main(){
  struct node *root = NULL;
  printf("MENU: 0)Exit 1)Create bst recursive 2)create bst iterative 3)Search key recursive 4)search key iterative 5)Inorder traversal recursive 6)Inorder traversal iterative  7)Preorder traversal recursive 8)Preorder traversal iterative 9)Postorder traversal recursive 10)Postorder traversal iterative");
  int choice = 1, key;
  while(choice!=0){
    printf("\nEnter choice: ");
    scanf("%d",&choice);
    switch(choice){
      case 1 : {
        printf("Enter key: ");
        scanf("%d",&key);
        root = createBSTrecusion(root, key);
        break;
      }
      case 2 : {
        printf("Enter key: ");
        scanf("%d",&key);
        root = createBSTiteration(root, key);
        break;
      }
      case 3 : {
        printf("Enter key to be searched: ");
        scanf("%d",&key);
        if(searchRecursive(root,key)) printf("\nKey found");
        else printf("Key not found");
        break;
      }
      case 4 : {
        printf("Enter key to be searched: ");
        scanf("%d",&key);
        if(searchIterative(root,key)) printf("\nKey found");
        else printf("Key not found");
        break;
      }
      case 5 : {
        printf("\nInorder traversal Recursive : ");
        inorderRecur(root);
        break;
      }
      case 6 : {
        printf("\nInorder traversal Iterative : ");
        inorderIterative(root);
        break;
      }
      case 7 : {
        printf("\nPreorder traversal Recursive : ");
        preorderRecur(root);
        break;
      }
      case 8 : {
        printf("\nPreorder traversal Iterative : ");
        preorderIterative(root);
        break;
      }
      case 9 : {
        printf("\nPostorder traversal Recursive : ");
        postorderRecur(root);
        break;
      }
      case 10 : {
        printf("\nPostorder traversal Iterative : ");
        postorderIterative(root);
        break;
      }
      default : break;
    }
  }
}