//Program to construct a open hash table
//Input - set of values, hash table size
//Output - hash table, number of successful and unsuccessful comparisons

#include<stdio.h>
#include<stdlib.h>
struct node **hashArray;
int hashSize;
int comparisons = 0;

struct node{
  int data;
  struct node *next;
};

void initialise(){
  for(int i = 0 ; i < hashSize ; i++){
    hashArray[i] = NULL;
  }
}

struct node *createnode(int data){
  struct node *newnode = (struct node*)malloc(sizeof(struct node));
  newnode->data = data;
  newnode->next = NULL;
  return newnode;
}
//Insert into the hash table
void insert(int ele){
  struct node *newnode = createnode(ele);
  int index = ele % hashSize;
  if(hashArray[index] == NULL){
    hashArray[index] = newnode;
  }else{
    struct node *temp = hashArray[index];
    while(temp->next != NULL){
      temp = temp->next;
    }
    temp->next = newnode;
  }
}

//print the list
void print(){
  printf("\nPrinting the hash table: \n");
  for(int i = 0 ; i < hashSize ; i++){
    struct node *temp = hashArray[i];
    printf("Index %d-> ",i+1);
    while(temp != NULL){
      printf("%d ",temp->data);
      temp = temp->next;
    }
    printf("\n");
  }
}

//Search from a hash table
int search(int ele){
  int index = ele % hashSize;
  struct node *temp = hashArray[index];
  while(temp != NULL){
    comparisons++;
    if(temp->data == ele) return 1;
    temp = temp->next;
  }
  return 0;
}

//Main function
int main(){
  int n, ele;
  printf("Enter hash table size: ");
  scanf("%d",&hashSize);
  hashArray = (struct node**)calloc(hashSize, sizeof(struct node*));
  initialise();
  printf("Enter the total number of elements: ");
  scanf("%d",&n);
  printf("Enter the elements :");
  for(int i = 0 ; i < n ; i++){
    ele = rand() % (1000 -0 + 1) + 0;
    printf("\nElement %d: %d",i+1, ele);
    insert(ele);
  }

  print();

  printf("\nEnter the element to be searched: ");
  scanf("%d",&ele);
  if(search(ele))printf("\nFound");
  else printf("\nNot found");
  printf("\nTotal comparisons: %d", comparisons);
}