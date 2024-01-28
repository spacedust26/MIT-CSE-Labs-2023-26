#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}NODE;
int main(){
    NODE *newnode1 = (NODE*)malloc(sizeof(NODE));
    NODE *newnode2 = (NODE*)malloc(sizeof(NODE));
    printf("Enter data 1: ");
    scanf("%d",&newnode1->data);
    printf("Enter data 2: ");
    scanf("%d",&newnode2->data);
    newnode1->next = newnode2;
    newnode2->next = NULL;
    NODE *temp = newnode1;
    printf("Displaying: ");
    while(temp!=0){
        printf("%d ",temp->data);
        temp = temp->next;
    }
}