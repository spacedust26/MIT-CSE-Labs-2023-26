#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define size 50
//NODE STRUTCURE
struct node{
    int data;
    struct node *left;
    struct node *right;
};
//STACK IMPLEMENTATION
typedef struct{
    struct node *a[size];
    int top;
}stack;
void push(stack *s,struct node *ele){
    if(s->top==size-1){
        printf("Stack overflow");
        return;
    }
    s->a[++s->top] = ele;
}
struct node *pop(stack *s){
    if(s->top==-1){
        printf("Stack underflow");
        return NULL;
    }
    return s->a[s->top--];
}
struct node *createnode(int data){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}
int eval(int x, int y, char op){
  switch(op){
    case '+': return x+y;
    case '-': return x-y;
    case '*': return x*y;
    case '/': return x/y;
  }
}
int evaluate(struct node *root){
  if(root==NULL)return 0;
  if(root->right == NULL && root->left == NULL) return (root->data);
  int x = evaluate(root->left);
  int y = evaluate(root->right);
  return eval(x,y,root->data);
}
int isOp(char x){
  return (x=='+' || x=='-' || x=='*' || x=='/');
}
void postorder(stack *s, char *exp){
  for(int i=0;i<strlen(exp);i++){
    if(exp[i]>='0' && exp[i]<='9'){
      push(s,createnode(exp[i]-'0'));
    }
    else if(isOp(exp[i])){
      struct node *root = createnode(exp[i]);
      root->right = pop(s);
      root->left = pop(s);
      push(s,root);
    }
  }
  struct node *res = pop(s);
  printf("Result: %d",evaluate(res));
}
int main(){
  char exp[50];
  stack s;
  s.top=-1;
  printf("Enter postorder expression: ");
  scanf("%s",exp);
  postorder(&s,exp);
}