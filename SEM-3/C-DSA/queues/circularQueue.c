//to implement a circular queue using arrays
#include<stdio.h>
#include<stdlib.h>
#define size 40
typedef struct{
    int a[size];
    //int *a;
    int front;
    int rear;
}CQUEUE;
void intilialise(CQUEUE *q){
    //q->a = (int *) calloc(size , sizeof(int)); //(dynamic allocation)
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
void enqueue(CQUEUE *q, int ele){
    if(isFull(q)){
        printf("Overflow");
        return;
    }
    if(isEmpty(q)){
        q->rear = q->front = 0;
        q->a[q->rear] = ele;
    }
    else{
        q->rear= (q->rear+1) % size;
        q->a[q->rear] = ele;
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
        printf("%d ",q->a[i]);
        i =(i+1)%size;
    }while(i!=q->rear);
    printf("%d ",q->a[q->rear]);
}
void peek(CQUEUE *q){
    if(isEmpty(q)){
        printf("Empty");
        return;
    }
    printf("\nPeek: %d",q->a[q->front]);
}
void main(){
    CQUEUE q;
    intilialise(&q);
    int choice=1;
    do{
        printf("\n1.enqueue 2.dequeue 3.display 4.peek 5.exit: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: {
                int ele;
                printf("\nEnter the element to be enqueued: ");
                scanf("%d",&ele);
                enqueue(&q, ele);
                break;
            }
            case 2: {
                printf("\nDequeued element: %d", q.a[q.front]);
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
}

