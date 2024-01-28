//to make a singly linked list for strings
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
//INSERT IN THE BEGINNING OF THE LIST
void insertBeginning(struct node **head){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter data to be inserted in the beginning: ");
    scanf("%d",&newnode->data);
    newnode->next = *head;
    *head = newnode;
}
//INSERT AT THE END OF THE LIST
void insertEnd(struct node **head){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter data to be inserted at the end: ");
    scanf("%d",&newnode->data);
    newnode->next = NULL;
    struct node *temp = *head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next = newnode;
}
//INSERT AT A GIVEN POSITION BASED ON INDEX
void insertPosition(struct node **head){
    int pos,i=1;
    printf("\nEnter the positon to enter data: ");
    scanf("%d",&pos);
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data to be inserted at the %d position: ",pos);
    scanf("%d",&newnode->data);
    struct node *temp = *head;
    while(i<pos){
        temp=temp->next;
        i++;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}
//DELETE AT BEGINNING
void deleteBeginning(struct node **head){
    struct node *temp = *head;
    if(*head==NULL){
        printf("\nEmpty linked list");
        return;
    }
    printf("\nFirst element deleted");
    *head = temp->next;
    free(temp);
}
//DELETE AT A GIVEN POSITION BASED ON INDEX
void deletePosition(struct node **head){
    if(*head==NULL){
        printf("\nEmpty linked list");
        return;
    }
    int pos,i=1;
    printf("\nEnter the position to be deleted: ");
    scanf("%d",&pos);
    printf("Element at %d positon deleted",pos);
    struct node *temp = *head;
    struct node *prev;
    while(i<=pos){
        prev =temp;
        temp= temp->next;
        i++;
    }
    prev->next = temp->next;
    free(temp);
}
//DELETE LAST ELEMENT
void deleteLast(struct node **head){
    if(*head==NULL){
        printf("\nEmpty linked list");
        return;
    }
    printf("\nLast element deleted");
    struct node *temp = *head;
    struct node *prev;
    while(temp->next!=NULL){
        prev =temp;
        temp= temp->next;
    }
    prev->next = NULL;
    free(temp);
}
//COUNT THE NUMBER OF NODES
int count(struct node *head){
    int count=0;
    if(head==NULL) return 0;
    else{
        struct node *temp= head;
        while(temp!=NULL){
            count++;
            temp= temp->next;
        }
    }
    return count;
}
//INVERT THE LIST
void invert(struct node **head){
    if(*head==NULL){
        printf("Empty linked list");
        return;
    }
    printf("Linked list inverted");
    struct node *prevnode=NULL;
    struct node *current=*head;
    struct node *nextnode=*head;
    while(nextnode!=NULL){
        nextnode = nextnode->next;
        current->next = prevnode;
        prevnode = current;
        current = nextnode;
    }
    *head = prevnode;
}
//MAIN
int main(){
    struct node *head= NULL;
    create(&head);
    display(head);
    printf("\nTotal node count: %d",count(head));
    insertBeginning(&head);
    display(head);
    insertEnd(&head);
    display(head);
    insertPosition(&head);
    display(head);
    deleteBeginning(&head);
    display(head);
    deleteLast(&head);
    display(head);
    deletePosition(&head);
    display(head);
    invert(&head);
    display(head);
}