/*Implement two circular queues of integers in a single array where first queue will run 
from 0 to N/2 and second queue will run from N/2+1 to N-1 where N is the size of
the array*/
#include<stdio.h>
#include<stdlib.h>
#define SIZE 40
typedef struct{
    int *a;
    int front;
    int rear;
}CQUEUE;
void intilialise(CQUEUE *q, int size){
    q->a = (int *) calloc(size , sizeof(int)); //(dynamic allocation)
    q->front = q->rear = -1;
}
int isEmpty(CQUEUE *q){
    if(q->front ==-1 && q->rear ==-1) return 1;
    else return 0;
}
int isFull(CQUEUE *q, int size){
    if((q->rear+1) % size == q->front)return 1;
    else return 0;
}
void enqueue(CQUEUE *q, int ele, int size){
    if(isFull(q,size)){
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
void dequeue(CQUEUE *q, int size){
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
void display(CQUEUE *q, int size){
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

void main(){
    int size = SIZE;
    CQUEUE q1;
    CQUEUE q2;
    intilialise(&q1,size/2);
    intilialise(&q2,size/2);
    enqueue(&q1,1,size/2);
    enqueue(&q1,3,size/2);
    enqueue(&q1,5,size/2);
    display(&q1,size/2);
    enqueue(&q2,2,size/2);
    enqueue(&q2,4,size/2);
    enqueue(&q2,6,size/2);
    dequeue(&q2,size/2);
    display(&q2,size/2);
}


