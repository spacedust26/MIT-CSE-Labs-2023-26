//to implement stacks using linked lists
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
//PUSH
void push(struct node **top, int ele){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = ele;
    newnode->next = *top;
    *top = newnode;
}
//POP
int pop(struct node **top){
    if(*top==NULL){
        printf("Empty stack");
        return -9;
    }
    int ele = (*top)->data;
    struct node *temp = *top;
    *top= temp->next;
    free(temp);
    return ele;
}
//DISPLAY
void display(struct node *top){
    if(top==NULL){
        printf("Empty stack");
        return;
    }
    printf("\nDisplay: ");
    struct node *temp = top;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp= temp->next;
    }
}
//MAIN
int main(){
    struct node *top = NULL;
    printf("\n\n\nMENU: 0)PUSH 1)POP 2)DISPLAY\n");
    int c=1;
    while(c!=0){
        int choice;
        printf("Enter menu choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 0:{
                int ele;
                printf("Enter element to be pushed: ");
                scanf("%d",&ele);
                push(&top,ele);
                break;
            }
            case 1:{
                printf("Popped element: %d",pop(&top));
                break;
            }
            case 2:{
                display(top);
                break;
            }
        }
        printf("\n1)Continue 0)Exit : ");
        scanf("%d",&c);
    }
}