//to perform polynomial arithmetic using linked lists
#include<stdio.h>
#include<stdlib.h>
struct node{
    int coeff;
    int exp;
    struct node *next;
};
//CREATE POLYNOMIAL BASED ON DECREASING POWER
void create(struct node **head){
    int n;
    printf("Enter number of terms in the polynomial: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        struct node *newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter coefficient of %d term: ", i+1);
        scanf("%d",&newnode->coeff);
        printf("Enter expononent of %d term: ",i+1);
        scanf("%d",&newnode->exp);
        newnode->next = NULL;
        struct node *temp ;
        if(*head==NULL || newnode->exp > (*head)->exp){
            newnode->next = *head;
            *head = newnode;
        }
        else{
            temp=*head;
            struct node *prev=NULL;
            while(temp->next!=NULL && temp->exp > newnode->exp){
                prev=temp;
                temp= temp->next;
            }
            if(temp->next == NULL){
                temp->next = newnode;
            }
            else{newnode->next = temp;
            prev->next = newnode;}
        }
    }
}

//MAIN
int main(){
    struct node *head1=NULL;
    struct node *head2=NULL;
    create(&head1);
    display(head1);
    create(&head2);
    display(head2);
}