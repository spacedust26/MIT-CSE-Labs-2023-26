//character stack implementation using arrays
#include<stdio.h>
#include<stdlib.h>
#define size 40
typedef struct{
    char a[size];
    int top;
}STACK;
void initialize(STACK *s){
    s->top=-1;
}
int isEmpty(STACK *s){
    if(s->top==-1)return 1;
    else return 0;
}
int isFull(STACK *s){
    if(s->top==size-1) return 1;
    else return 0;
}
void push(STACK *s, char ele){
    if(!isFull(s)) s->a[++s->top] = ele;
    else printf("Overflow");
}
char pop(STACK *s){
    if(!isEmpty(s)) return s->a[s->top--];
    else{
        printf("Underflow");
        return '*';
    }
}
void display(STACK *s){
    for(int i=0;i<=s->top;i++){
        printf("%c ",s->a[i]);
    }
}
int main(){
    STACK s;
    initialize(&s);
    push(&s,'A');
    push(&s,'b');
    push(&s,'C');
    push(&s,'d');
    pop(&s);
    display(&s);
}