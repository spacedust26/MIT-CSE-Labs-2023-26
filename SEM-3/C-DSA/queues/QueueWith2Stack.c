/*Implement a queue with two stacks without transferring the elements of the second
stack back to stack one. (use stack1 as an input stack and stack2 as an output stack)*/
#include<stdio.h>
#include<stdlib.h>
typedef struct{
    int *a;
    int top;
    int size;
}STACK;
STACK *createStack(int size){
    STACK *s = (STACK *)malloc(sizeof(STACK));
    s->size=size;
    s->a = (int *)calloc(s->size, sizeof(int));
    s->top =-1;
    return s;
}
int isEmpty(STACK *s){
    if(s->top == -1)return 1;
    else return 0;
}
int isFull(STACK *s){
    if(s->top == s->size - 1)return 1;
    else return 0;
}
void push(STACK *s, int ele){
    if(isFull(s)){
        printf("Overflow");
        return;
    }
    s->a[++s->top]= ele;
}
int pop(STACK *s){
    if(isEmpty(s)){
        printf("Underflow");
        return -99;
    }
    else{
        return s->a[s->top--];
    }
}
typedef struct {
    STACK *s1;
    STACK *s2;
}QUEUE;
QUEUE *createQueue(int size){
    QUEUE *q = (QUEUE*)malloc(sizeof(QUEUE));
    q->s1 = createStack(size);
    q->s2 = createStack(size);
    return q;
}
void enqueue(QUEUE *q, int ele){
    push(q->s1,ele);
}
int dequeue(QUEUE *q){
    if(isEmpty(q->s1) && isEmpty(q->s2)){
        printf("Empty");
        return -99;
    }
    if(isEmpty(q->s2)){
        while(!isEmpty(q->s1)){
            int ele = pop(q->s1);
            push(q->s2, ele);
        }
    }
    return pop(q->s2);
}
int main(){
    QUEUE *q = createQueue(10);
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);

    printf("%d\n", dequeue(q)); // Should print 1
    printf("%d\n", dequeue(q)); // Should print 2

    enqueue(q,4);
    printf("%d\n", dequeue(q)); // Should print 3
    printf("%d\n", dequeue(q));
}