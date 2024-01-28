//TO CREATE A BINARY TREE USING ITERATIVE APPROACH
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
void inorderIterative(struct node *root){
    struct node *temp;
    int flag = 1;
    stack s1;
    stack *s = &s1;
    s->top = -1;
    if(root==NULL){
        printf("Empty binary tree");
        return;
    }
    temp=root;
    while(flag){
        while(temp!=NULL){
            push(s,temp);
            temp=temp->left;
        }
        if(s->top!=-1){
            temp = pop(s);
            printf(" %d ",temp->data);
            temp=temp->right;
        }
        else{
            flag=0;
        }
    }
}
//ITERVATIVE POSTORDER TRAVERSAL
void postorderIterative(struct node *root){
    struct stack{
        struct node *node;
        int flag;
    };
    struct node *temp=root;
    struct stack s[20];
    int top=-1;
    if(root==NULL){
        printf("Tree is empty");
        return;
    }
    while(1){
        while(temp!=NULL){
            s[++top].node = temp;
            s[top].flag =1;
            temp = temp->left;
        }
        while(s[top].flag<0){
            temp = s[top--].node;
            printf(" %d ",temp->data);
            if(top==-1){
                return;
            }
        }
        temp = s[top].node;
        temp=temp->right;
        s[top].flag=-1;
    }

}
//ITERATIVE PREOREDR TRAVERSAL
void preorderIterative(struct node *root){
    stack *s,s1;
    s=&s1;
    s->top =-1;
    struct node *temp;
    if(root==NULL){
        printf("Tree is empty");
        return;
    }
    push(s,root);
    while(s->top!=-1){
        temp=pop(s);
        printf(" %d ",temp->data);
        if(temp->right!=NULL) push(s,temp->right);
        if(temp->left!=NULL) push(s,temp->left);
    }
}
//MAIN FUNCTION
int main(){
    struct node *root = create();
    printf("\nIterative Inorder traversal: ");
    inorderIterative(root);
    printf("\nIterative Postorder traversal: ");
    postorderIterative(root);
    printf("\nIterative Preorder traversal: ");
    preorderIterative(root);
}