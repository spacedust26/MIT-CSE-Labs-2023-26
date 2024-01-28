/*Reverse a stack using recursion [Note: Only the IsEmpty, Push and Pop operations
are allowed on stack*/
#include<stdio.h>
#include<stdlib.h>
#define size 40
typedef struct{
    int a[size];
    int top;
}STACK;
void initialize(STACK *s){
    s->top=-1;
}
int isEmpty(STACK *s){
    if(s->top==-1)return 1;
    else return 0;
}
void push(STACK *s, int ele){
    if(s->top!=size-1) s->a[++s->top] = ele;
    else printf("Overflow");
}
int pop(STACK *s){
    if(!isEmpty(s)) return s->a[s->top--];
    else{
        printf("Underflow");
        return -26;
    }
}
void display(STACK *s){
    for(int i=0;i<=s->top;i++){
        printf("%d ",s->a[i]);
    }
}
void insert(STACK *s, int data) {
    if (isEmpty(s)) {
        push(s, data);
        return;
    }
    int temp = pop(s);
    insert(s, data);
    push(s, temp);
}
void reverse(STACK *s) {
    if (!isEmpty(s)) {
        int temp = pop(s);
        reverse(s);
        insert(s, temp);
    }
}
int main(){
    STACK s;
    initialize(&s);
    int i=0;
    push(&s,1);
    push(&s,2);
    push(&s,3);
    push(&s,4);
    push(&s,5);
    reverse(&s);
    display(&s);
}