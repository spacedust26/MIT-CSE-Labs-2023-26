//to check whether a string is palindrome or not using stacks
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
void display(STACK *s){
    for(int i=0;i<=s->top;i++){
        printf("%c ",s->a[i]);
    }
}
void palindrome(STACK *s, char *str){
    char exp[size];
    int count=0;
    strcpy(exp,str);
    for(int i=0;i<strlen(str);i++){
        push(s,str[i]);
    }
    for(int i=0;i<strlen(exp);i++){
        if(exp[i]!=pop(s)){
            count =0;
            break;
        }
        else count =1;
    }
    if(count==1) printf("Palindrome");
    else printf("Not palindrome");
}
int main(){
    STACK s;
    initialize(&s);
    char str[size];
    printf("Enter string: ");
    scanf("%s",str);
    palindrome(&s,str);
}