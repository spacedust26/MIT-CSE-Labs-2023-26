//POLYNOMIAL ARITHMETIC USING LINKED LISTS
#include<stdio.h>
#include<stdlib.h>
struct node{
    int coeff;
    int exp;
    struct node *next;
};
//CREATE POLYNOMIAL LINKED LIST
void create(struct node **head, int coeff, int exp){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->coeff = coeff;
    newnode->exp = exp;
    newnode->next = NULL;
   if(*head== NULL|| newnode->exp > (*head)->exp){
        newnode->next = *head;
        *head= newnode;
    }
    else{
        struct node *temp =*head;
        while(temp->next!=NULL && temp->exp > newnode->exp){
            temp=temp->next;
        }
        newnode->next = temp->next;
        temp->next= newnode;
    }
}
//TO TAKE NUMBER OF TERMS
void terms(struct node **head){
    int n,i,exp,coeff;
    printf("Enter number of terms in the polynomial: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter coefficient of %d term: ",i+1);
        scanf("%d",&coeff);
        printf("Enter exponent of %d term: ",i+1);
        scanf("%d",&exp);
        create(head,coeff,exp);
    }
}
//DISPLAY POLYNOMIAL
void display(struct node *head){
    if(head==NULL){
        printf("Empty polynomial linked list");
    }
    else{
        struct node *temp = head;
        while(temp!=NULL){
            printf(" %dx^%d ",temp->coeff, temp->exp);
            temp= temp->next;
            if(temp!=NULL){
                printf("+");
            }
            else
                printf("\n");
        }
    }
}
//ADDITON OF POLYNOMIAL
void add(struct node **head1, struct node **head2){
    struct node *temp1 = *head1;
    struct node *temp2 = *head2;
    struct node *head3=NULL;
    while(temp1!=NULL && temp2!=NULL){
        if(temp1->exp == temp2->exp){
            create(&head3,(temp1->coeff + temp2->coeff), temp1->exp);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else if( temp1->exp > temp2->exp){
            create(&head3,temp1->coeff, temp1->exp);
            temp1 = temp1->next;
        }
        else{
            create(&head3,temp2->coeff, temp2->exp);
            temp2 = temp2->next;
        }
    }
    while(temp1!=NULL){
        create(&head3,temp1->coeff,temp1->exp);
        temp1= temp1->next;
    }
    while(temp2!=NULL){
        create(&head3,temp2->coeff,temp2->exp);
        temp2= temp2->next;
    }
    display(head3);
}
//SUBTRACT OF POLYNOMIAL
void subtract(struct node **head1, struct node **head2){
    struct node *temp1 = *head1;
    struct node *temp2 = *head2;
    struct node *head3=NULL;
    while(temp1!=NULL && temp2!=NULL){
        if(temp1->exp == temp2->exp){
            create(&head3,(temp1->coeff - temp2->coeff), temp1->exp);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else if( temp1->exp > temp2->exp){
            create(&head3,temp1->coeff, temp1->exp);
            temp1 = temp1->next;
        }
        else{
            create(&head3,-temp2->coeff, temp2->exp);
            temp2 = temp2->next;
        }
    }
    while(temp1!=NULL){
        create(&head3,temp1->coeff,temp1->exp);
        temp1= temp1->next;
    }
    while(temp2!=NULL){
        create(&head3,-temp2->coeff,temp2->exp);
        temp2= temp2->next;
    }
    display(head3);
}
//MULTIPLICATION OF POLYNOMIAL
void multiply(struct node *head1, struct node *head2){
    struct node *head3 = NULL;
    struct node *temp1 = head1;
    struct node *temp2 = head2;
    while(temp1!=NULL){
        temp2=head2;
        while(temp2!=NULL){
            int coeff = temp1->coeff * temp2->coeff;
            int exp = temp1->exp + temp2->exp;
            create(&head3,coeff,exp);
            temp2=temp2->next;
        }
        temp1 = temp1->next;
    }
    struct node *temp3 = head3;
    struct node *head4 = NULL;
    while(temp3!=NULL){
        if (temp3->next != NULL && temp3->exp == temp3->next->exp) {
            int sum = temp3->coeff;
            while (temp3->next != NULL && temp3->exp == temp3->next->exp) {
                sum += temp3->next->coeff;
                temp3 = temp3->next;
            }
            create(&head4, sum, temp3->exp);
        }
        else{
            create(&head4,temp3->coeff,temp3->exp);
        }
        temp3=temp3->next;
    }
    display(head4);
}
//MAIN
int main(){
    struct node *head1= NULL;
    struct node *head2= NULL;
    printf("POLYNOMIAL 1: ");
    terms(&head1);
    display(head1);
    printf("\n");
    printf("POLYNOMIAL 2: ");
    terms(&head2);
    display(head2);
    printf("ADDITION: ");
    add(&head1,&head2);
    printf("SUBTRACTION: ");
    subtract(&head1,&head2);
    printf("MULTIPLICATION: ");
    multiply(head1,head2);
}