/*Write a menu driven program to implement doubly linked list without header node
to insert into and delete from both the sides*/
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left;
    struct node *right;
};
void insertFront(struct node **list, int data){
    struct node *newnode=  (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    if(*list==NULL){
        *list= newnode;
    }
    else{
       (*list)->left= newnode;
       newnode->right = *list;
       *list = newnode;
    }
}
void insertLast(struct node **list, int data){
    struct node *newnode=  (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    struct node *temp;
    if(*list==NULL){
        *list= newnode;
    }
    else{
        temp=*list;
        while(temp->right!=NULL){
            temp=temp->right;
        }
       temp->right = newnode; 
       newnode->left = temp; 
    }
}
void display(struct node *list){
    if(list==NULL){
        printf("Empty doubly linked list");
        return;
    }
    struct node *temp = list;
    while(temp!=NULL){
        printf(" %d ",temp->data);
        temp=temp->right;
    }
}
int deleteFront(struct node **list){
    if(*list==NULL){
        printf("Empty linked list");
        return -9;
    }
    struct node *temp= *list;
    int ele = temp->data;
    if(temp->right!=NULL){
        temp->right->left = NULL;
    }
    *list = temp->right;
    free(temp);
    return ele;
}
int deleteLast(struct node **list){
    if(*list==NULL){
        printf("Empty linked list");
        return -9;
    }
    struct node *temp = *list;
    while(temp->right!=NULL){
        temp = temp->right;
    }
    int ele = temp->data;
    if(temp->left!=NULL){
        temp->left->right = NULL;
    }
    else{
        *list = NULL;
    }
    free(temp);
    return ele;
}
int main(){
    printf("\nMENU: 0)INSERT FRONT 1)INSERT LAST 2)DELETE FRONT 3)DELETE LAST 4)DISPLAY 5)EXIT\n");
    struct node *list= NULL;
    int choice;
    do{
        printf("\nEnter menu choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 0:{
                int ele;
                printf("Enter element to insert first: ");
                scanf("%d",&ele);
                insertFront(&list,ele);
                break;
            }
            case 1:{
                int ele;
                printf("Enter element to insert last: ");
                scanf("%d",&ele);
                insertLast(&list,ele);
                break;
            }
            case 2:{
                int ele = deleteFront(&list);
                printf("%d element deleted from front\n",ele);
                break;
            }
            case 3:{
                int ele = deleteLast(&list);
                printf("%d element deleted from last\n",ele);
                break;
            }
            case 4:{
                printf("\nDisplaying: ");
                display(list);
                break;
            }
            case 5:{
                break;
            }
        }
    }while(choice!=5);
}