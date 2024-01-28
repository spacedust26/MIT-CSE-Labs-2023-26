//TO IMPLEMENT A DOUBLY LINKED LIST;
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
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
        scanf("%d",&newnode->data);
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
        printf("%d ",temp->data);
        temp = temp->next;
    }
}
//LENGTH OF THE DOUBLY LINKED LIST LIST
int length(){
    struct node *temp= head;
    int count=0;
    if(head==NULL){
        return 0;
    }
    do{
        count++;
        temp=temp->next;
    }while(temp!=NULL);
    return count;
}
//INSERT IN THE BEGINNING
void insertbeginning(){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter data to be inserted at the beginning: ");
    scanf("%d",&newnode->data);
    newnode->prev = newnode->next =NULL;
    head->prev = newnode;
    newnode->next = head;
    head = newnode;
}
//INSERT AT THE END
void insertend(){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter data to be inserted at the end: ");
    scanf("%d",&newnode->data);
    newnode->prev = newnode->next =NULL;
    struct node* temp = head;
    while(temp->next!=NULL){
        temp= temp->next;
    }
    newnode->prev= temp;
    temp->next = newnode;
    temp = newnode;
}
//INSERT AT A GIVEN POSITION
void insertAtPosition(){
    int pos,i=1;
    printf("\nEnter the position to be inserted: ");
    scanf("%d",&pos);
    if(pos<0 || pos> length()){
        printf("Invalid position");
        return ;
    }
    else{
        if(pos==0){
            insertbeginning();
        }
        if(pos==length()) insertend();
        else{
            struct node *newnode = (struct node*)malloc(sizeof(struct node));
            printf("Enter data to be inserted at %d position: ",pos);
            scanf("%d",&newnode->data);
            newnode->prev = newnode->next =NULL;
            struct node *temp = head;
            while(i<pos){
                temp = temp->next;
                i++;
            }
            newnode->prev = temp;
            newnode->next = temp->next;
            temp->next = newnode;
            newnode->next->prev = newnode;
        }
    }
}
//DELETE FIRST
void deleteFirst(){
    struct node *temp = head;
    if(head ==NULL){
        printf("Empty doubly linked list");
    }
    else{
        printf("\nFirst element deleted");
        head = head->next;
        head->prev =NULL;
        free(temp);
    }
}
//DELETE LAST
void deleteLast(){
    struct node *temp = head;
    struct node *tail;
    if(head==NULL){
        printf("Empty doubly linked list");
    }
    else{
        while(temp->next!=NULL){
            temp=temp->next;
        }
        printf("\nLast element deleted");
        tail= temp;
        tail->prev->next =NULL;
        tail = tail->prev;
        free(temp);
    }
}
//DELETE AT A GIVEN POSITION
void deletePosition(){
    int pos, i=1;
    printf("\nEnter position to be deleted: ");
    scanf("%d",&pos);
    if(pos==0){
        deleteFirst();
    }
    if(pos==length()){
        deleteLast();
    }
    else{
        printf("\nElement at %d deleted",pos);
        struct node *temp = head;
        while(i<pos){
            temp= temp->next;
            i++;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
    }
}
//MAIN
int main(){
    create();
    display();
    printf("\nTotal number of nodes: %d",length());
    insertbeginning();
    display();
    insertend();
    display();
    insertAtPosition();
    display();
    deleteFirst();
    display();
    deleteLast();
    display();
    deletePosition();
    display();
}