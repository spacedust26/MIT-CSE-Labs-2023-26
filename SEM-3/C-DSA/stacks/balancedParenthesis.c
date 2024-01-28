//to check if the parethesis is balanced in a given equation
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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
void balance(STACK *s, char *str){
    for(int i=0;i<strlen(str);i++){
        if(str[i]=='(') push(s,str[i]);
        if(str[i]==')'){
            if(s->top == -1){
                printf("Unbalanced parenthesis");
                return;
            }
            if(s->a[s->top] == '(') pop(s);
        }
    }
    if(!isEmpty(s)) printf("Unbalanced parenthesis");
    else printf("Balanced parenthesis");
}
int main(){
    STACK s;
    initialize(&s);
    char str[30];
    printf("Enter the equation: ");
    scanf("%s",str);
    balance(&s,str);
}