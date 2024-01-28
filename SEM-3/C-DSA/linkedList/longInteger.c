/*Add two long positive integers represented using circular doubly linked list with
header node.*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
    int data;
    struct node *prev;
    struct node *next;
};
//CREATE NEWNODE
struct node *createNode(int data){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->prev= NULL;
    newnode->next= NULL;
    return newnode;
}
// INSERT NODE
void insert(struct node **head, int data){
    struct node *newnode = createNode(data);
    struct node *temp;
    if(*head==NULL){
        newnode->next = newnode->prev = newnode;
        *head = newnode;
    }
    else{
        temp=*head;
        while(temp->next!= *head){
            temp=temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
        newnode->prev = temp;
        (*head)->prev = newnode;
    }
}
//REVERSE
void reverse(struct node **head){
    if(*head == NULL){
        printf("Empty list");
        return;
    }
    struct node *current= *head;
    struct node *temp;
    do{
        temp = current->next;
        current->next = current->prev;
        current->prev = temp;
        current = temp;

    }while(current!=*head);
    *head = (*head)->next;
}
//DISPLAY
void display(struct node *head){
    if(head==NULL){
        printf("Empty list");
        return;
    }
    struct node *temp = head->next;
    while(temp!=head){
        printf(" %d ",temp->data);
        temp=temp->next;
    }
}
//ADDITION OF LONG INTEGERS
void addLongInteger(struct node *head1, struct node *head2){
    struct node *head3=NULL;
    struct node *temp1 = head1;
    while(temp1->next!= head1){
            temp1=temp1->next;
        }
    struct node *temp2 = head2;
    while(temp2->next!= head2){
            temp2=temp2->next;
        }
    int sum=0, carry=0;
    while(temp1!=head1 && temp2!=head2){
        sum = (temp1->data + temp2->data + carry)%10;
        carry = (temp1->data + temp2->data + carry)/10;
        insert(&head3,sum);
        temp1=temp1->prev;
        temp2=temp2->prev;
    }
    while(temp1!=head1){
        sum = (temp1->data + carry)%10;
        carry = (temp1->data + carry)/10;
        insert(&head3,sum);
        temp1 = temp1->prev;
    }
    while(temp2!=head2){
        sum = (temp2->data + carry)%10;
        carry = (temp2->data + carry)/10;
        insert(&head3,sum);
        temp2 = temp2->prev;
    }
    if(carry!=0){
        insert(&head3,carry);
    }
    insert(&head3,-1);
    reverse(&head3);
    display(head3);
}
//MAIN
int main(){
    struct node *head1=NULL;
    struct node *head2=NULL;
    insert(&head1,-1);//HEADER NODE
    insert(&head2,-1);
    char num1[100], num2[100];
    printf("Enter first long positive integer: ");
    scanf("%s",num1);
    printf("Enter second long positive integer: ");
    scanf("%s",num2);
    for(int i=0;i<strlen(num1);i++){
        int d = num1[i] - '0';
        insert(&head1,d);
    }
    for(int i=0;i<strlen(num2);i++){
        int d = num2[i] - '0';
        insert(&head2,d);
    }
    printf("\nFirst number: ");
    display(head1);
    printf("\nSecond number: ");
    display(head2);
    printf("\nAddition of long integers: ");
    addLongInteger(head1,head2);
}
// #include<stdio.h>
// #include<stdlib.h>
// #include<string.h>
// struct node{
//   int data;
//   struct node *prev;
//   struct node *next;
// };
// typedef struct node NODE;
// NODE *create(int data){
//   struct node *newnode=(struct node*)malloc(sizeof(struct node));
//   newnode->data=data;
//   newnode->prev=newnode->next=NULL;
//   return newnode;
// }
// NODE *insert_rear(NODE *head,int info){
//   NODE *newnode=create(info);
//   if(head==NULL){
//     head=newnode;
//   }
//   else{
//     NODE *temp=head;
//     while(temp->next!=NULL){
//       temp=temp->next;
//     }
//     temp->next=newnode;
//     temp->next->prev=temp;
//   }
//   return head;
// }

// NODE *insert_front(NODE *head,int info){
//   NODE *newnode=create(info);
//   if(head==NULL){
//     head=newnode;
//   }
//   else{
//     head->prev=newnode;
//     newnode->next=head;
//     head=newnode;
//   }
//   return head;
// }

// void display(NODE *head){
//   if(head==NULL){
//     printf("Empty list");
//     return;
//   }
//   NODE *temp=head;
//   while(temp!=NULL){
//     printf("%d ",temp->data);
//     temp=temp->next;
//   }
//   printf("\n");
// }
// int main(){
//   char num1[40],num2[40];
//   NODE *head1=NULL;
//   NODE *head2=NULL;
//   printf("Enter long integer 1: ");
//   scanf("%s",num1);
//   for(int i=0;i<strlen(num1);i++){
//     head1=insert_rear(head1,num1[i]-'0');
//   }
//   printf("Enter long integer 2: ");
//   scanf("%s",num2);
//   for(int i=0;i<strlen(num2);i++){
//     head2=insert_rear(head2,num2[i]-'0');
//   }
//   NODE *head3=NULL;
//   struct node *temp1=head1;
//   struct node *temp2=head2;
//   while(temp1->next!=NULL){
//     temp1=temp1->next;
//   }
//   while(temp2->next!=NULL){
//     temp2=temp2->next;
//   }
//   int sum=0;
//   int carry=0;
//   while(temp1!=NULL && temp2!=NULL){
//     sum = (temp1->data + temp2->data+ carry)%10;
//     carry =(temp1->data + temp2->data+ carry)/10;
//     head3=insert_front(head3,sum);
//     temp1=temp1->prev;
//     temp2=temp2->prev;
//   }
//   while(temp1!=NULL){
//     sum = (temp1->data+ carry)%10;
//     carry =(temp1->data + carry)/10;
//     head3=insert_front(head3,sum);
//     temp1=temp1->prev;
//   }
//    while(temp2!=NULL){
//     sum = (temp2->data+ carry)%10;
//     carry =(temp2->data + carry)/10;
//     head3=insert_front(head3,sum);
//     temp2=temp2->prev;
//   }
//   if(carry!=0)head3=insert_front(head3,carry);
//   display(head1);
//   display(head2);
//   display(head3);
// }