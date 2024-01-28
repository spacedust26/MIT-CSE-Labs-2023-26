/*Reverse a doubly linked list containing words in the data field*/
//TO IMPLEMENT A DOUBLY LINKED LIST;
#include<stdio.h>
#include<stdlib.h>
struct node{
    char data[20];
    struct node *next;
    struct node *prev;
};
struct node *head;
// CREATE A DOUBLY LINKED LIST
void create(){
    head=NULL;
    struct node *temp;
    int choice=1;
    while(choice){
        struct node *newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%s",newnode->data);
        newnode->next =NULL;
        newnode->prev =NULL;
        if(head==NULL){
            head = temp = newnode;
        }
        else{
        temp->next = newnode;
        newnode->prev = temp;
        temp = newnode;
        }
        printf("1->continue 0->stop : ");
        scanf("%d",&choice);
    }
}
//DISPLAY DOUBLY LINKED LIST
void display(){
    struct node *temp = head;
    printf("\nDisplay: ");
    while(temp!=NULL){
        printf("%s ",temp->data);
        temp = temp->next;
    }
}
//REVERSE
void reverse(){
    struct node *temp = head;
    struct node *before = NULL;
    if(temp==NULL){
        printf("Empty doubly linked list\n");
        return;
    }
    while(temp!=NULL){
        before = temp->prev;
        temp->prev = temp->next;
        temp->next = before;
        temp=temp->prev;

    }
    head = before->prev;
}
//MAIN
int main(){
    create();
    display();
    reverse();
    display();
}