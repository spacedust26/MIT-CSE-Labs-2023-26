//to convert an infix expression to prefix expression
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
void reverse(char *exp){
    int i,j;
    for(i=0,j=strlen(exp)-1;i<j;i++,j--){
        char temp = exp[i];
        exp[i]=exp[j];
        exp[j]=temp;
    }
}
void infixtoprefix(STACK *s, char *exp){
    char prefix[size];
    int j=0;
    reverse(exp);
    for(int i=0;i<strlen(exp);i++){
        if(exp[i]>='0' && exp[i] <='9' || exp[i]>='A' && exp[i] <='Z' || exp[i]>='a' && exp[i] <='z'){
            prefix[j++] = exp[i];
        }
        if(exp[i]==')'){
            push(s,exp[i]);
        }
        if(exp[i]=='('){
            while(s->a[s->top]!=')' && !isEmpty(s)){
                prefix[j++] = pop(s);
            }
            if(s->a[s->top]==')' && !isEmpty(s)){
                pop(s);
            }
        }
        if(exp[i]== '+' || exp[i]== '-' || exp[i]== '*' || exp[i]== '/' || exp[i]== '%'){
            while (precedence(exp[i]) < precedence(s->a[s->top]) && !isEmpty(s) && s->a[s->top]!='('){
                prefix[j++]=pop(s);
            }
            push(s,exp[i]);
        }
    }
    while(!isEmpty(s)){
        prefix[j++]=pop(s);
    }
    prefix[j]='\0';
    reverse(prefix);
    printf("%s",prefix);
}
int main(){
    char inf[size];
    STACK s;
    initialize(&s);
    printf("Enter infix expression: ");
    scanf("%s",inf);
    printf("Prefix expression: ");
    infixtoprefix(&s,inf);
}