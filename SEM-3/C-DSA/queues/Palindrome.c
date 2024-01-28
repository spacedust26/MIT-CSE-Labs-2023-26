/*Write a program to check whether given string is a palindrome using a dequeue.*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define size 40
typedef struct{
    char a[size];
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
void enqueue(QUEUE *q, char ele){
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
char dequeue(QUEUE *q){
    if(isEmpty(q)){
        printf("Underflow");
        return '*';
    }
    char ele = q->a[q->front];
    if(q->front==q->rear){
        q->front = q->rear=-1;
    }
    else{
        q->front++;
    }
    return ele;
}
int palindrome(char *str, QUEUE *q1, QUEUE *q2){
    for(int i=0;i<strlen(str);i++){
        enqueue(q1,str[i]);
    }
    for(int i=strlen(str)-1;i>=0;i--){
        enqueue(q2,str[i]);
    }
    for(int i=0;i<strlen(str);i++){
        char a = dequeue(q1);
        char b = dequeue(q2);
        if(a!=b){
            return 0;
        }
    }
    return 1;
}
int main(){
    char str[size];
    QUEUE q1;
    QUEUE q2;
    initialise(&q1);
    initialise(&q2);
    printf("Enter string: ");
    scanf("%s", str);
    if(palindrome(str,&q1,&q2))printf("Palindrome");
    else printf("not palindrome");
    return 0;
}
