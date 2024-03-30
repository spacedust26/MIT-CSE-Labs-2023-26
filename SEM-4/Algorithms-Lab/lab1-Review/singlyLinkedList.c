//Write an algorithm and program to implement a sinlgy linked list which supports the following operations 
//i. Create the list by adding each node at the front. 
//ii. Insert a new node to the left of the node whose key value is read as an input. 
//iii. Delete all occurrences of a given key, if it is found. Otherwise, display appropriate message. 
//iv. Search a node based on its key value. 
//v. Display the contents of the list. 

#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node *next;
};

struct node *createNode(int data){
  struct node *newnode = (struct node*)malloc(sizeof(struct node));
  newnode->data = data;
  newnode->next = NULL;
  return newnode;
}

struct node *insertFront(struct node *head, int data){
  struct node *newnode = createNode(data);
  if(head == NULL) head = newnode;
  else{
    newnode->next = head;
    head = newnode;
  }
  return head;
}

struct node *insertLeft(struct node *head, int data, int key){
  struct node *temp = head;
  struct node *prev = NULL;
  while(temp != NULL){
    if(temp->data == data){
      struct node *newnode = createNode(key);
      newnode->next = temp;
      if(prev == NULL)head = newnode;
      else prev->next = newnode;
      break; 
    }
    prev = temp;
    temp = temp->next;
  }
  if(temp == NULL){
    printf("\nNo such data found. Hence cannot be inserted.");
  }
  return head;
}

struct node *delete(struct node *head, int key){
  int flag = 0;
  struct node *temp = head;
  struct node *prev = NULL;
  while(temp != NULL){
    if(temp->data == key){
      flag = 1;
      if(prev == NULL){
        head = temp->next;
      }
      prev->next = temp->next;
    }
    prev = temp;
    temp = temp->next;
  }
  if(flag == 0) printf("\nNone to be deleted");
  else printf("\nDelete successful");
  return head;
}

int search(struct node *head , int key){
  struct node *temp = head;
  while(temp != NULL){
    if(temp->data == key) return 1;
    temp = temp->next;
  }
  return 0;
}

void display(struct node *head){
  if(head == NULL) printf("\nEmpty list.");
  struct node *temp = head;
  while(temp != NULL){
    printf("%d ",temp->data);
    temp = temp->next;
  }
}

int main(){
  struct node *head = NULL;
  printf("MENU: 1)add node to front 2)insert a new node to left of the node read 3)delete all occurances of a key if found 4)search a node 5)display list 6)exit: ");
  int choice,key,data;
  while(1){
    printf("\nEnter menu choice: ");
    scanf("%d",&choice);
    switch(choice){
      case 1:{
        printf("Enter key: ");
        scanf("%d",&key);
        head = insertFront(head, key);
        break;
      }
      case 2:{
        printf("Enter key: ");
        scanf("%d",&key);
        printf("Enter node to the left of which key must be inserted: ");
        scanf("%d",&data);
        head = insertLeft(head,data, key);
        break;
      }
      case 3:{
        printf("Enter key to be deleted: ");
        scanf("%d",&key);
        head = delete(head,key);
        break;
      }
      case 4:{
        printf("Enter key to be searched: ");
        scanf("%d",&key);
        if(search(head,key))printf("\nFound");
        else printf("\nNot found");
        break;
      }
      case 5:{
        printf("\nDisplaying content: ");
        display(head);
        break;
      }
      default: break;
    }
  }
}
