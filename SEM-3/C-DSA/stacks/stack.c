//stack implementation using arrays
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
        return -99;
    }
}
void display(STACK *s){
    for(int i=0;i<=s->top;i++){
        printf("%d ",s->a[i]);
    }
}
int main(){
    STACK s;
    initialize(&s);
    int choice=1;
    while(choice!=4){
        printf("\n1.push 2.pop 3.display 4.exit: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: {
                int ele;
                printf("\nEnter element to be pushed: ");
                scanf("%d",&ele);
                push(&s,ele);
                break;
            }
            case 2: {
                printf("\nPopped element: %d",pop(&s));
                break;
            }
            case 3: {
                printf("\nDisplay: ");
                display(&s);
                break ;
            }
            default: break;
        }
    }
}