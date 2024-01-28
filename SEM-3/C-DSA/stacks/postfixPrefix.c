//to convert a postfix expression into prefix expression
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define size 40
typedef struct{
    char a[size][size];
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
void push(STACK *s, char *ele){
    if(!isFull(s)) strcpy(s->a[++s->top],ele) ;
    else printf("Overflow");
}
char *pop(STACK *s){
    char *ch = (char*)malloc(size*sizeof(char));
    strcpy(ch,s->a[s->top--]);
    return ch;
}
void postfixPrefix(STACK *s, char *postfix){
    char op1[size], op2[size];
    for(int i=0;i<strlen(postfix);i++){
        if((postfix[i]>='0' && postfix[i]<='9')||(postfix[i]>='a' && postfix[i]<='z')||(postfix[i]>='A' && postfix[i]<='Z')){
            char *temp = (char*)malloc(2*sizeof(char));
            temp[0]= postfix[i];
            temp[1]='\0';
            push(s,temp);
        }
        if(postfix[i]=='+' || postfix[i]=='-' || postfix[i]=='*' || postfix[i]=='/' || postfix[i]=='%' ){
            if(!isEmpty(s)) strcpy(op2,pop(s));
            if(!isEmpty(s)) strcpy(op1,pop(s));
            int n = strlen(op1) + strlen(op2) + 1;
            char *temp = (char *)calloc(n ,sizeof(char));
            temp[0]= postfix[i];
            strcat(temp,op1);
            strcat(temp, op2);
            push(s,temp);
        }
    }
    printf("Prefix expression: %s", s->a[0]);
}
int main(){
    STACK s;
    initialize(&s);
    char postfix[size];
    printf("Enter postfix expression: ");
    scanf("%s",postfix);
    postfixPrefix(&s,postfix);
}