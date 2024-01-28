//SEARCHING A BINARY TREE
#include<stdio.h>
#include<stdlib.h>
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
//CREATE NODE FUNCTION
struct node *createnode(int data){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}
//CREATE BINARY TREE USING ITERATIVE APPROACH
struct node *create(){
    struct node *root=NULL;
    struct node *temp=NULL;
    struct node *newnode;
    int x;
    printf("Enter data of root node(-1 for no node): ");
    scanf("%d",&x);
    if(x==-1)return NULL;
    root = createnode(x);
    temp=root;
    struct node *stack[40];
    int top = -1;
    while(1){
        printf("Enter left child of %d (-1 for no node): ",temp->data);
        scanf("%d",&x);
        if(x!=-1){
            newnode = createnode(x);
            temp->left=newnode;
            stack[++top]= newnode;
        }
        printf("Enter right child of %d (-1 for no node): ",temp->data);
        scanf("%d",&x);
        if(x!=-1){
            newnode = createnode(x);
            temp->right=newnode;
            stack[++top]= newnode;
        }
        if(top==-1)break;
        temp = stack[top--];
    }
    return root;
}
//ITERATIVE INORDER TRAVERSAL
int inorderSearch(struct node *root,int ele){
    struct node *temp;
    int flag = 1;
    stack s1;
    stack *s = &s1;
    s->top = -1;
    if(root==NULL){
        printf("Empty binary tree");
        return -9;
    }
    temp=root;
    int t=0;
    while(flag){
        while(temp!=NULL){
            push(s,temp);
            temp=temp->left;
        }
        if(s->top!=-1){
            temp = pop(s);
            if(temp->data == ele){
              t=1;
              return t;
            }
            temp=temp->right;
        }
        else{
            flag=0;
        }
    }
    return t;
}
//ITERVATIVE POSTORDER TRAVERSAL
int postorderSearch(struct node *root,int ele){
    struct stack{
        struct node *node;
        int flag;
    };
    struct node *temp=root;
    struct stack s[20];
    int top=-1;
    if(root==NULL){
        printf("Tree is empty");
        return -99;
    }
    int t=0;
    while(1){
        while(temp!=NULL){
            s[++top].node = temp;
            s[top].flag =1;
            temp = temp->left;
        }
        while(s[top].flag<0){
            temp = s[top--].node;
            if(temp->data == ele){
              t=1;
              return t;
            }
            if(top==-1){
                return 0;
            }
        }
        temp = s[top].node;
        temp=temp->right;
        s[top].flag=-1;
    }
  return t;
}
//ITERATIVE PREOREDR TRAVERSAL
int preorderSearch(struct node *root,int ele){
    stack *s,s1;
    s=&s1;
    s->top =-1;
    struct node *temp;
    if(root==NULL){
        printf("Tree is empty");
        return -99;
    }
    int t=0;
    push(s,root);
    while(s->top!=-1){
        temp=pop(s);
        if(temp->data == ele){
          t=1;
          return t;
        }
        if(temp->right!=NULL) push(s,temp->right);
        if(temp->left!=NULL) push(s,temp->left);
    }
    return t;
}
//MAIN FUNCTION
int main(){
    struct node *root = create();
    int ele;
    printf("Enter element to be searched: ");
    scanf("%d",&ele);
    printf("\nInorder search: ");
    if(inorderSearch(root,ele)) printf("Found");
    else printf("Not found");
    printf("\nPostorder search: ");
    if(postorderSearch(root,ele)) printf("Found");
    else printf("Not found");
    printf("\nPreorder search: ");
    if(preorderSearch(root,ele)) printf("Found");
    else printf("Not found");
}