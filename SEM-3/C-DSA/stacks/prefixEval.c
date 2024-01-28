//to evaluate a prefix expression
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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
int operate(int op1, int op2, char op){
    switch(op){
        case '+': return op1+op2;
        case '-': return op1-op2;
        case '*': return op1*op2;
        case '/': {
            if(op2==0){
                printf("Divide by 0 invalid");
                exit(0);
            }
            return op1/op2;
        }
        case '%': return op1%op2;
    }
}
void prefixEval(STACK *s, char *exp){
    int op1, op2;
    for(int i=strlen(exp);i>=0;i--){
        if(exp[i]>= '0' && exp[i]<='9') push(s, exp[i]-'0');
        if(exp[i]== '+' || exp[i]== '-' || exp[i]== '*' || exp[i]== '/' || exp[i]== '%'){
            if(!isEmpty(s)){
                op1 = pop(s);
            }
            if(!isEmpty(s)){
                op2 = pop(s);
            }
            int res = operate(op1,op2,exp[i]);
            push(s,res);
        }
    }
    printf("Result: %d",pop(s));
}
int main(){
    STACK s;
    initialize(&s);
    char exp[30];
    printf("Enter prefix expression: ");
    scanf("%s",exp);
    prefixEval(&s,exp);
}