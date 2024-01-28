//to implement queues using arrays
#include<stdio.h>
#include<stdlib.h>
#define size 40
typedef struct{
    int a[size];
    int front;
    int rear;
}QUEUE;
void initialise(QUEUE *q){
    q->front = q->rear = -1;
}
int isEmpty(QUEUE *q){
    if(q->front == -1 && q->rear ==-1) return 1;
    else return 0;
}
int isFull(QUEUE *q){
    if(q->rear == size-1) return 1;
    else return 0;
}
void enqueue(QUEUE *q, int ele){
    if(isFull(q)){
        printf("Overflow");
        return;
    }
    if(isEmpty(q)){
        q->front = q->rear = 0;
        q->a[q->rear]=ele;
    }
    else q->a[++q->rear] = ele;
}
void dequeue(QUEUE *q){
    if(isEmpty(q)){
        printf("Underflow");
        return;
    }
    if(q->front==q->rear){
        q->front = q->rear=-1;
    }
    else{
        q->front++;
    }
}
void display(QUEUE *q){
    if(isEmpty(q)){
        printf("Empty queue");
        return;
    }
    for(int i=q->front ;i<=q->rear;i++){
        printf("%d ",q->a[i]);
    }
}
void peek(QUEUE *q){
    if(isEmpty(q)){
        printf("Empty queue");
        return;
    }
    printf("\nPeek: %d",q->a[q->front]);
}
int main(){
    QUEUE q;
    initialise(&q);
    int choice;
    do{
        printf("\n1.enqueue 2.dequeue 3.display 4.peek 5.exit: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:{
                int ele;
                printf("\nEnter element to be enqueued: ");
                scanf("%d",&ele);
                enqueue(&q,ele);
                break;
            }
            case 2:{
                printf("\nElement dequeued: %d",q.a[q.front]);
                dequeue(&q);
                break;
            }
            case 3: {
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
