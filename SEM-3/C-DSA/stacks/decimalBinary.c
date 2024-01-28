//to convert a decimal number into binary
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
int isFull(STACK *s){
    if(s->top==size-1) return 1;
    else return 0;
}
void push(STACK *s, int ele){
    if(!isFull(s)) s->a[++s->top] = ele;
    else printf("Overflow");
}
int pop(STACK *s){
    if(!isEmpty(s)) return s->a[s->top--];
    else{
        printf("Underflow");
        return -26;
    }
}
void dectobin(STACK *s, int d){
    int b;
    while(d!=0){
        b = d%2;
        push(s,b);
        d/=2;
    }
    printf("Bianry value: ");
    while(!isEmpty(s)){
        printf("%d ",pop(s));
    }
}
int main(){
    int d;
    STACK s;
    initialize(&s);
    printf("Enter decimal number: ");
    scanf("%d",&d);
    dectobin(&s,d);
}