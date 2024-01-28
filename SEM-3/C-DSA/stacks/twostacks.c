//to implement 2 stacks within an array
#include<stdio.h>
#include<stdlib.h>
#define size 40
typedef struct{
    int a[size];
    int top1;
    int top2;
}STACK;
int overflow(STACK *s){
    if((s->top1) +1 == s->top2) return 1;
    else return 0;
}
void push1(STACK *s, int ele){
    if(!overflow(s)) s->a[++s->top1] = ele;
    else printf("Overflow");
}
int pop1(STACK *s){
    if(s->top1==-1){
        printf("Underflow");
        return -26;
    }
    else{
       return s->a[s->top1--];
    }
}
void push2(STACK *s, int ele){
    if(!overflow(s)) s->a[--s->top2] = ele;
    else printf("Overflow");
}
int pop2(STACK *s){
    if(s->top2==size){
        printf("Underflow");
        return -26;
    }
    else{
       return s->a[s->top2++];
    }
}
int main(){
    STACK s;
    s.top1 = -1;
    s.top2 = size;
    int choice=1;
    while(choice!=5){
        printf("\n1.push1 2.pop1 3.push2 4.pop2 5.exit: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: {
                int ele;
                printf("\nEnter element to be pushed in stack1: ");
                scanf("%d",&ele);
                push1(&s,ele);
                break;
            }
            case 2: {
                printf("\nPopped element of stack1: %d",pop1(&s));
                break;
            }
            case 3: {
                int ele;
                printf("\nEnter element to be pushed in stack2: ");
                scanf("%d",&ele);
                push2(&s,ele);
                break;
            }
            case 4: {
                printf("\nPopped element of stack2: %d",pop2(&s));
                break;
            }
            default: break;
        }
    }
}