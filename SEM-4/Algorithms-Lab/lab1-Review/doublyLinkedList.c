//Algorithm to implement a doubly linked list
//i. Create the list by adding each node at the front. 
// ii. Insert a new node to the left of the node whose key value is read as an input. 
// iii. Delete all occurrences of a given key, if it is found. Otherwise, display 
// appropriate message. 
// iv. Search a node based on its key value. 
// v. Display the contents of the list. 

#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node *left;
  struct node *right;
};

struct node *createNode(int data){
  struct node *newnode = (struct node *)malloc(sizeof(struct node));
  newnode->data = data;
  newnode->left = newnode->right = NULL;
  return newnode;
}

//Insert front - add node to the front to create a list
struct node *insertFront(struct node *head, int data){
  struct node *newnode = createNode(data);
  if(head == NULL){
    head = newnode;
  }else{
    newnode->right = head;
    head->left = newnode;
    head = newnode;
  }
  return head;
}

//Insert key to the left 
struct node *leftKey(struct node *head, int data, int key){
  if(head == NULL) printf("\nEmpty list");
  else{
    struct node *temp = head;
    while(temp != NULL && temp->data != data){
      temp = temp->right;
    }
    if(temp == NULL) printf("\nNo such node found");
    else{
      struct node *newnode = createNode(key);
      newnode->left = temp-> left;
      newnode->right = temp;
      temp->left->right = newnode;
      temp->left = newnode;
    }
  }
  return head;
}

//Delete key occurances
struct node *delete(struct node *head, int data){
  int flag = 0;
  if(head == NULL) printf("Empty list");
  else{
    struct node *temp = head;
    while(temp != NULL){
      if(temp->data == data){
        if(temp->left != NULL){
          temp->left->right = temp->right;
        }
        if(temp->right != NULL){
          temp->right->left = temp->left;
        }
        if(temp->left == NULL){
          head = temp->right;
          head->left = NULL;
        }
        if(temp->right == NULL){
          temp->left->right = NULL;
        }
        flag = 1;
      }
      temp = temp->right;
    }
  }
  if(flag == 0){
    printf("No node deleted");
  }
  return head;
}

//Search a node
int search(struct node *head,int data){
  if(head==NULL) printf("Empty list");
  else{
    struct node *temp = head;
    while(temp!= NULL){
      if(temp->data == data){
        return 1;
      }
      temp = temp->right;
    }
  }
  return 0;
}

//Display function
void display(struct node *head){
  if(head == NULL) printf("\nEmpty list");
  else{
    struct node *temp = head;
    while(temp!=NULL){
      printf("%d ",temp->data);
      temp = temp->right;
    }
  }
}

//Main function
int main(){
  struct node *head = NULL;
  int choice=1, data;
  printf("MENU: 0)End 1)Add key 2)Insert left to key 3)Delete key occurances 4)Search key 5)Display ");
  while(choice!=0){
    printf("\nEnter choice: ");
    scanf("%d",&choice);
    switch(choice){
      case 1 : {
        printf("Enter key to be added to list: ");
        scanf("%d",&data);
        head = insertFront(head, data);
        break;
      }
      case 2 : {
        printf("Enter value of node to the left of which key need to be inserted: ");
        scanf("%d",&data);
        int key;
        printf("Enter key value: ");
        scanf("%d",&key);
        head = leftKey(head,data,key);
        break;
      }
      case 3 : {
        printf("Enter key to be deleted: ");
        scanf("%d",&data);
        head = delete(head, data);
        break;
      }
      case 4 : {
        printf("Enter key to be searched: ");
        scanf("%d",&data);
        if(search(head, data)!= 0) printf("\nKey found");
        else printf("\nKey not found");
        break;
      }
      case 5 : {
        printf("\nDisplaying list: ");
        display(head);
        break;
      }
      default: break;
    }
  }
  return 0;
}

