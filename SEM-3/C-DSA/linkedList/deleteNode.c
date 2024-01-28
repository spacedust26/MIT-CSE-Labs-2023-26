/*You're given the pointer to the head node of a sorted singly linked list, where the data 
in the nodes is in ascending order. Delete as few nodes as possible so that the list does 
not contain any value more than once (deleting duplicates). The given head pointer
may be null indicating that the list is empty.*/
#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};
//ENTER DATA
void create(struct node **head, int data){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
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
        printf(" %d ",temp->data);
        temp=temp->next;
    }
}
//DELETE DUPLICATE ELEMENTS
void delete(struct node **head){
    if(*head==NULL){
        printf("\nEmpty linked list");
        return;
    }
    struct node *temp = *head;
    while(temp->next!=NULL){
        if(temp->data==temp->next->data){
            struct node *del = temp->next;
            temp->next = temp->next->next;
            free(del);
        }
        else{
            temp = temp->next;
        }
    }
}
//MAIN
int main(){
    int choice=1,data;
    struct node *head=NULL;
    int i=1;
    //CREATE A ASCENDING LINKED LIST
    do{
        printf("Enter data %d: ",i);
        scanf("%d",&data);
        create(&head,data);
        i++;
        printf("1->add 0->stop: ");
        scanf("%d",&choice);
    }while(choice);
    printf("\nLinked list: ");
    display(head);
    //PRINT LINKED LIST WITHOUT DUPLICATES
    printf("\nLinked list without duplicates: ");
    delete(&head);
    display(head);
}