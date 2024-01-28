//to concatenate 2 lists
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
//CREATION OF A SINGELY LINKED LIST
void create(struct node **head){
    int choice=1;
    do{
        struct node *newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d",&newnode->data);
        newnode->next = NULL;
        struct node *temp;
        if(*head==NULL){
            *head =temp= newnode;
        }
        else{
            temp->next = newnode;
            temp = newnode;
        }
        printf("1:continue 0:stop ");
        scanf("%d",&choice);
    }while(choice);
}
// DISPLAY
void display(struct node *head){
    printf("\nDisplay: ");
    if(head==NULL){
        printf("Empty linked list");
        return;
    }
    struct node *temp = head;
    while(temp!= NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
}
//CONCATENATE
void concatenate(struct node **head1, struct node **head2){
    if(*head1==NULL || *head2==NULL){
        printf("One of the linked lists is empty");
        return;
    }
    else if(*head1==NULL && *head2==NULL){
        printf("Both the linked lists are empty");
        return;
    }
    else{
        struct node *temp= *head1;
        while(temp->next!=NULL){
            temp= temp->next;
        }
        temp->next = *head2;
    }
}
int main(){
    struct node *head1 = NULL;
    struct node *head2= NULL;
    printf("LIST 1:\n");
    create(&head1);
    display(head1);
    printf("\nLIST 2:\n");
    create(&head2);
    display(head2);
    printf("\nAFTER CONCATENATION: ");
    concatenate(&head1, &head2);
    display(head1);
}