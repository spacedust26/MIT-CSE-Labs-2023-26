//IMPLEMENT AN ITERATIVE BINARY SEARCH TREE
#include<stdio.h>
#include<stdlib.h>
#define size 40
struct node{
  int data;
  struct node *left;
  struct node *right;
};
//STACK IMPLEMENTATION
typedef struct{
    struct node *a[size];
    int top;
}stack;
void push(stack *s,struct node *ele){
    if(s->top==size-1){
        printf("Stack overflow");
        return;
    }
    s->a[++s->top] = ele;
}
struct node *pop(stack *s){
    if(s->top==-1){
        printf("Stack underflow");
        return NULL;
    }
    return s->a[s->top--];
}
//INSERT ITERATIVE FUNCTION
struct node *createNode(int data){
  struct node *newnode= (struct node*)malloc(sizeof(struct node));
  newnode->data=data;
  newnode->left = newnode->right=NULL;
  return newnode;
}
struct node *insert(struct node *root, int data){
  struct node *newnode = createNode(data);
  if(root==NULL){
    root=newnode;
  }
  else{
    struct node *temp = root;
    struct node *parent = NULL;
    while(temp!=NULL){
      parent=temp;
      if(data<temp->data){
        temp=temp->left;
      }
      else if(data>temp->data){
        temp=temp->right;
      }
      else{
        free(newnode);
        return root;
      }
    }
    if(data<parent->data){
      parent->left = newnode;
    }
    else{
      parent->right = newnode;
    }
  }
  return root;
}
//DELETION FUNCTION
struct node *delete(struct node *root, int key){
  struct node *parent=NULL;
  struct node *temp = root;
  while(temp!=NULL && temp->data!=key){
    parent=temp;
    if(key<temp->data){
      temp = temp->left;
    }
    else {
      temp=temp->right;
    }
  }

  if(temp==NULL) return root; //key not found
  //2 children
  //using inorder successor
  if(temp->left !=NULL && temp->right!= NULL){
    struct node *successor = temp->right;
    struct node *successorParent = temp;
    while(successor->left != NULL){
      successorParent = successor;
      successor= successor->left;
    }
    temp->data = successor->data;
    temp=successor;
    parent=successorParent;
  }

  //using inorder predecessor
  /*if(temp->left !=NULL && temp->right!= NULL){
    struct node *predecessor = temp->left;
    struct node *predecessorParent = temp;
    while(predecessor->right != NULL){
      predecessorParent = predecessor;
      predecessor= predecessor->right;
    }
    temp->data = predecessor->data;
    temp=predecessor;
    parent=predecessorParent;
  }*/

  //1 child no child
  struct node *child = (temp->left!=NULL)? temp->left : temp->right;
  if(child!=NULL){
    if(parent==NULL)
      root=NULL;
    else if(temp==parent->left)
      parent->left = child;
    else 
      parent->right = child;
    free(temp);
  }
  else{
    if(parent==NULL)
      root=NULL;
    else if(temp==parent->left)
      parent->left = NULL;
    else 
      parent ->right = NULL;
    free(temp);
  }
  return root;
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
//ITERATIVE INORDER TRAVERSAL
void inorderIterative(struct node *root){
    struct node *temp;
    int flag = 1;
    stack s1;
    stack *s = &s1;
    s->top = -1;
    if(root==NULL){
        printf("Empty binary tree");
        return;
    }
    temp=root;
    while(flag){
        while(temp!=NULL){
            push(s,temp);
            temp=temp->left;
        }
        if(s->top!=-1){
            temp = pop(s);
            printf(" %d ",temp->data);
            temp=temp->right;
        }
        else{
            flag=0;
        }
    }
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
  inorderIterative(root);
  printf("\nEnter key to be deleted: ");
  scanf("%d",&key);
  root= delete(root,key);
  inorderIterative(root);
  printf("\nEnter key to be searched: ");
  scanf("%d",&key);
  if(searchRecursion(root,key))
    printf("Key found\n");
  else printf("Key not found\n");
}