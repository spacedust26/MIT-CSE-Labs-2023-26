/*Reverse a singly linked list containing words in the data field using recursion*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node {
    char data[20];
    struct node *next;
};
//CREATE STRING NODES
void create(struct node **head, char data[20]){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    strcpy(newnode->data , data);
    newnode->next = NULL;
    static struct node *temp;
    if(*head==NULL){
        *head = temp = newnode;
    }
    else{
        temp->next = newnode;
        temp = newnode;
    }
}
//DISPLAY FUNCTION
void display(struct node *head){
    struct node *temp = head;
    while(temp!=NULL){
        printf(" %s ",temp->data);
        temp=temp->next;
    }
}
//REVERSE LIST USING RECUSRIONS
void reverse(struct node *head){
    struct node *temp= head;
    if(temp==NULL){
        return;
    }
    reverse(temp->next);
    printf("%s ",temp->data);
}
//MAIN
int main(){
    int choice=1;
    char data[20];
    struct node *head=NULL;
    int i=1;
    //CREATE A STRING LIST
    do{
        printf("Enter data %d: ",i);
        scanf("%s",data);
        create(&head,data);
        i++;
        printf("1->add 0->stop: ");
        scanf("%d",&choice);
    }while(choice);
    printf("\nLinked list of strings: ");
    display(head);
    //PRINT REVERSED LIST
    printf("\nReversed list: ");
    reverse(head);
}