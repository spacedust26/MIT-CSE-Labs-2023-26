//to make a singly linked list
#include<stdio.h>
#include<stdlib.h>
struct node{
    char data[20];
    struct node *next;
};
//CREATION OF A SINGELY LINKED LIST
void create(struct node **head){
    int choice=1;
    do{
        struct node *newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%s",&newnode->data);
        newnode->next = NULL;
        struct node *temp;
        if(*head==NULL){
            *head =temp= newnode;
        }
        else{
            temp->next = newnode;
            temp = newnode;
        }
        printf("Enter 1:continue 0:stop : ");
        scanf("%d",&choice);
    }while(choice);
}
// DISPLAY
void display(struct node *head){
    printf("Display: ");
    if(head==NULL){
        printf("Empty linked list");
        return;
    }
    struct node *temp = head;
    while(temp!= NULL){
        printf("%s ",temp->data);
        temp = temp->next;
    }
}
//MAIN
int main(){
    struct node *head= NULL;
    create(&head);
    display(head);
}