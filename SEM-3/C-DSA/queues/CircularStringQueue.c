//to implement a circular queue for strings
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define size 40
typedef struct{
    char a[size][size];
    // char *a[size];
    int front;
    int rear;
}CQUEUE;
void intilialise(CQUEUE *q){
    q->front = q->rear = -1;
}
int isEmpty(CQUEUE *q){
    if(q->front ==-1 && q->rear ==-1) return 1;
    else return 0;
}
int isFull(CQUEUE *q){
    if((q->rear+1) % size == q->front)return 1;
    else return 0;
}
void enqueue(CQUEUE *q, char *ele){
    if(isFull(q)){
        printf("Overflow");
        return;
    }
    if(isEmpty(q)){
        q->rear = q->front = 0;
        strcpy(q->a[q->rear] , ele);
        //q->a[q->rear] = ele;
    }
    else{
        q->rear= (q->rear+1) % size;
         strcpy(q->a[q->rear] , ele);
    //     q->a[q->rear] = ele;
     }
}
void dequeue(CQUEUE *q){
    if(isEmpty(q)){
        printf("Underflow");
        return;
    }
    if(q->front == q->rear){
        q->front = q->rear =-1;
    }
    else{
        q->front = (q->front+1)%size;
    }
}
void display(CQUEUE *q){
    if(isEmpty(q)){
        printf("Empty circular queue");
        return;
    }
   int i = q->front;
   do{
        printf("%s ",q->a[i]);
        i = (i+1)%size;
    }while(i!=q->rear);
    printf("%s ",q->a[q->rear]);
}
void peek(CQUEUE *q){
    if(isEmpty(q)){
        printf("Empty");
        return;
    }
    printf("\nPeek: %s",q->a[q->front]);
}
int main(){
    CQUEUE q;
    intilialise(&q);
    int choice=1;
    do{
        printf("\n1.enqueue 2.dequeue 3.display 4.peek 5.exit: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: {
                char ele[size];
                printf("\nEnter the element to be enqueued: ");
                scanf("%s",ele);
                enqueue(&q, ele);
                break;
            }
            case 2: {
                printf("\nDequeued element: %s", q.a[q.front]);
                dequeue(&q);
                break;
            }
            case 3:{
                printf("\nDisplaying: ");
                display(&q);
                break;
            }
            case 4:{
                peek(&q);
                break;
            }
            default: break;
        }
    }while(choice!=5);
    return 0;
}

