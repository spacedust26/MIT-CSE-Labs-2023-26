//to convert an infix expression into postfix expression
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
int precedence(char ch){
    switch(ch){
        case '+':
        case '-':
            return 2;
        case '*':
        case '/':
        case '%':
            return 3;
        default :
            return 0;
    }
}
void infixtopostfix(STACK *s, char *exp){
    int i,j=0;
    char postfix[size];
    for(i=0;i<strlen(exp);i++){
        if((exp[i]>='0' && exp[i]<='9') || (exp[i]>='a' && exp[i]<='z') || (exp[i]>='A' && exp[i]<='Z')){
            postfix[j++]= exp[i];
        }
        if(exp[i]=='('){
            push(s,exp[i]);
        }
        if(exp[i]==')'){
            while(!isEmpty(s) && s->a[s->top]!='('){
                postfix[j++]= pop(s);
            }
            if(!isEmpty(s) && s->a[s->top]=='('){
                pop(s);
            }
        }
        if(exp[i]=='+' || exp[i]=='-' || exp[i]=='*' || exp[i]=='/' || exp[i]=='%'){
            while((!isEmpty(s)) && (precedence(exp[i]) <= precedence(s->a[s->top]) ) && (s->a[s->top]!='(')){
                postfix[j++] = pop(s);
            }
            push(s,exp[i]);
        }
    }
    while(!isEmpty(s)){
        postfix[j++]=pop(s);
    }
    postfix[j]= '\0';
    printf("Postfix expression: %s",postfix);
}
int main(){
    STACK s;
    initialize(&s);
    char exp[size];
    printf("Enter infix expression: ");
    scanf("%s",exp);
    infixtopostfix(&s,exp);
}
