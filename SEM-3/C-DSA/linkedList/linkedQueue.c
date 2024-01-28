//to implement queues using linked list
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *front=NULL;
struct node *rear=NULL;
//ENQUEUE
void enqueue(int ele){
    struct node * newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data= ele;
    newnode->next = NULL;
    if(front == NULL && rear == NULL){
        front = rear = newnode;
    }
    else{
        rear->next = newnode;
        rear = newnode;
    }
}
//DEQUEUE   
int dequeue(){
    if(front==NULL && rear==NULL){
        printf("Empty queue");
        return -9;
    }
    int ele = front->data;
    if(front == rear){
        front = rear = NULL;
    }
    else{
        struct node *temp = front;
        front = temp->next;
        free(temp);
    }
    return ele;
}
//DISPLAY
void display(){
    if(front==NULL && rear ==NULL){
        printf("Empty queue");
        return;
    }
    printf("\nDisplay: ");
    struct node *temp= front;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
   }
}
//MAIN
int main(){
    printf("\n\nMENU: 0)Enqueue 1)Dequeue 2)Display: \n");
    int c=1;
    while(c){
        int choice;
        printf("Enter menu choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 0:{
                printf("Enter element to be enqueued: ");
                int ele;
                scanf("%d",&ele);
                enqueue(ele);
                break;
            }
            case 1:{
                printf("Dequeued element: %d",dequeue());
                break;
            }
            case 2:{
                display();
                break;
            }
        }
        printf("\n1 to continue 0 to exit: ");
        scanf("%d",&c);
    }
}