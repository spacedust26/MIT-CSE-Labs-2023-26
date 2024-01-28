//TO CONSTRUCT A SPARSE MATRIX
#include<stdio.h>
#include<stdlib.h>
struct node{
  int row;
  int column;
  int value;
  struct node *next;
};
//CREATE FUNCTION
struct node *createNode(int row,int column,int value){
  struct node *newnode =(struct node*)malloc(sizeof(struct node));
  newnode->row=row;
  newnode->column=column;
  newnode->value=value;
  newnode->next=NULL;
  return newnode;
}
struct node *insert(struct node *head,int row, int column, int value){
  struct node *newnode = createNode(row,column,value);
  if(head==NULL){
    head=newnode;
  }
  else{
    struct node *temp=head;
    while(temp->next!=NULL){
      temp=temp->next;
    }
    temp->next=newnode;
  }
  return head;
}
//PRINT MATRIX
void print(struct node *head,int rowNum,int columnNum){
  if(head==NULL){
    printf("Empty sparse matrix");
    return;
  }
  printf("Displaying sparse matrix:\n");
  struct node *temp=head;
  for(int i=0;i<rowNum;i++){
    for(int j=0;j<columnNum;j++){
      if(temp!=NULL && temp->row==i && temp->column==j){
        printf("\t%d\t",temp->value);
        temp=temp->next;
      }
      else printf("\t0\t");
    }
    printf("\n");
  }
}
//MAIN
int main(){
  struct node *head=NULL;
  int value,rowNum,columnNum;
  printf("Enter total number of rows and columns: ");
  scanf("%d %d",&rowNum,&columnNum);
  for(int i=0;i<rowNum;i++){
    for(int j=0;j<columnNum;j++){
      printf("Enter value of %d row %d column: ",i,j);
      scanf("%d",&value);
      if(value!=0){
        head=insert(head,i,j,value);
      }
    }
  }
  print(head,rowNum,columnNum);
}
