//to implement priority queue ascending and descending
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
void AscendingPriorityenqueue(QUEUE *q, int ele){
    if(isFull(q)){
        printf("Overflow");
        return;
    }
    else{
        int pos =-1;
        pos = q->rear;
        q->rear = q->rear+1;
        while(pos>=0 && ele <= q->a[pos]){
            q->a[pos+1] = q->a[pos];
            pos = pos -1;
        }
        q->a[pos+1]= ele;
        if(q->front == -1){
            q->front = 0;
        }
    }
}
void DescendingPriorityenqueue(QUEUE *q, int ele){
    if(isFull(q)){
        printf("Overflow");
        return;
    }
    else{
        int pos =-1;
        pos = q->rear;
        q->rear = q->rear+1;
        while(pos>=0 && ele > q->a[pos]){
            q->a[pos+1] = q->a[pos];
            pos = pos -1;
        }
        q->a[pos+1]= ele;
        if(q->front == -1){
            q->front = 0;
        }
    }
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
int AscendingPriorityDequeue(QUEUE *q){
    if(isEmpty(q)){
        printf("Underflow");
        return -9;
    }
    else{
        int pos=0;
        int min= q->a[0];
        for(int i=1;i<=q->rear;i++){
            if(q->a[i]<min){
                min = q->a[i];
                pos =i;
            }
        }
        for(int i=pos;i<q->rear;i++){
            q->a[i] = q->a[i+1];
        }
        q->rear = q->rear-1;
        return min;
    }
}
int DescendingPriorityDequeue(QUEUE *q){
    if(isEmpty(q)){
        printf("Underflow");
        return -9;
    }
    else{
        int pos=0;
        int max= q->a[0];
        for(int i=1;i<=q->rear;i++){
            if(q->a[i]>max){
                max = q->a[i];
                pos =i;
            }
        }
        for(int i=pos;i<q->rear;i++){
            q->a[i] = q->a[i+1];
        }
        q->rear = q->rear-1;
        return max;
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
        printf("\n0.enqueue 1.AscendingPriorityenqueue 2.dequeue 3.display 4.peek 5.exit 6.DescendingPriorityenqueue 7.AscendingPriorityDequeue 8.DescendingPriorityDequeue: ");
        scanf("%d",&choice);
        switch(choice){
            case 0:{
                int ele;
                printf("\nEnter element to be enqueued: ");
                scanf("%d",&ele);
                enqueue(&q,ele);
                break;
            }
            case 1:{
                int ele;
                printf("\nEnter element to be enqueued: ");
                scanf("%d",&ele);
                AscendingPriorityenqueue(&q,ele);
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
            case 6:{
                int ele;
                printf("\nEnter element to be enqueued: ");
                scanf("%d",&ele);
                DescendingPriorityenqueue(&q,ele);
                break;
            }
            case 7:{
                printf("AscendingPriorityDequeue: %d ", AscendingPriorityDequeue(&q));
                break;
            }
            case 8:{
                printf("DescendingPriorityDequeue: %d ", DescendingPriorityDequeue(&q));
                break;
            }
            default: break;
        }
    }while(choice!=5);

}
