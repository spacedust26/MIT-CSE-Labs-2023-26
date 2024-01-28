//to convert a prefix expression into postfix expression
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
void reverse(char *exp){
    int i,j;
    for(i=0,j=strlen(exp)-1;i<j;i++,j--){
        char temp = exp[i];
        exp[i]=exp[j];
        exp[j]=temp;
    }
}
void prefixPostfix(STACK *s, char *prefix){
    char op1[size], op2[size];
    reverse(prefix);
    for(int i=0;i<strlen(prefix);i++){
        if((prefix[i]>='0' && prefix[i]<='9')||(prefix[i]>='a' && prefix[i]<='z')||(prefix[i]>='A' && prefix[i]<='Z')){
            char *temp = (char*)malloc(2*sizeof(char));
            temp[0]= prefix[i];
            temp[1]='\0';
            push(s,temp);
        }
        if(prefix[i]=='+' || prefix[i]=='-' || prefix[i]=='*' || prefix[i]=='/' || prefix[i]=='%' ){
            if(!isEmpty(s)) strcpy(op1,pop(s));
            if(!isEmpty(s)) strcpy(op2,pop(s));
            int n = strlen(op1) + strlen(op2) + 1;
            char *temp = (char *)calloc(n ,sizeof(char));
            strcat(temp,op1);
            strcat(temp, op2);
            temp[n-1]= prefix[i];
            push(s,temp);
        }
    }
    printf("Postfix expression: %s", s->a[0]);
}
int main(){
    STACK s;
    initialize(&s);
    char prefix[size];
    printf("Enter prefix expression: ");
    scanf("%s",prefix);
    prefixPostfix(&s,prefix);
}