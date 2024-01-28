/*Given a queue of integers, write a program to reverse the queue, using only the
following operations:
i. enqueue(x): Add an item x to rear of queue.
ii. dequeue() : Remove an item from front of queue.
iii. empty() : Checks if a queue is empty or not.
*/
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
void enqueue(QUEUE *q, int ele){
    if(q->rear == size-1){
        printf("Overflow");
        return;
    }
    if(isEmpty(q)){
        q->front = q->rear = 0;
        q->a[q->rear]=ele;
    }
    else q->a[++q->rear] = ele;
}
// int dequeue(QUEUE *q){
//     if(isEmpty(q)){
//         printf("Underflow");
//         return -9;
//     }
//     int ele = q->a[q->front];
//     int pos= q->front;
//     for(int i=q->front+1;i<=q->rear;i++){
//         q->a[pos++]= q->a[i];
//     }
//     q->rear--;
//     return ele;
// }

int dequeue(QUEUE *q){
    if(isEmpty(q)){
        printf("Underflow");
        return -9;
    }
    int ele = q->a[q->front];
    if(q->front==q->rear){
        q->front = q->rear=-1;
    }
    else{
        q->front++;
    }
    return ele;
}
void reverseQueue(QUEUE* queue) {
    if (isEmpty(queue)) {
        return;
    }
    int item = dequeue(queue);
    reverseQueue(queue);
    enqueue(queue, item);
}
int main(){
    QUEUE q;
    initialise(&q);
    int n,arr[size];
    printf("Enter digit size: ");
    scanf("%d",&n);
    printf("Enter the digits: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
        enqueue(&q,arr[i]);
    }
//     int j,i;
//     for(i=0;i<n-1;i++){
//         for(j=0;j<n-i-1;j++){
//             int a = dequeue(&q);
//             enqueue(&q,a);
//         }
//         q.front = i+1;
//     }
//     printf("Reverse: ");
//    for(int i=0;i<n;i++){
//     printf("%d ",q.a[i]);
//    }
    reverseQueue(&q);
    for(int i=0;i<n;i++){
        printf("%d ",q.a[i]);
    }
}
