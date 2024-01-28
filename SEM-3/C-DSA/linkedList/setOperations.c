// //TO PERFORM UNION AND INTERSECTION OF TWO SETS WITH AND WITHOUT HEADER USING SINGLY LINKED LIST
// #include<stdio.h>
// #include<stdlib.h>
// #include<stdbool.h>
// struct node{
//     int data;
//     struct node *next;
// };
// //CREATION OF A NEWNODE
// void create(struct node **head, int data){
//     struct node *newnode = (struct node*)malloc(sizeof(struct node));
//     newnode->data = data;
//     newnode->next = NULL;
//     static struct node *temp;
//     if(*head==NULL){
//         *head = temp = newnode;
//     }
//     else{
//         temp->next = newnode;
//         temp = newnode;
//     }
// }
// // DISPLAY
// void display(struct node *head){
//     printf("\nDisplay: ");
//     if(head==NULL){
//         printf("Empty linked list");
//         return;
//     }
//     struct node *temp = head;
//     while(temp!= NULL){
//         printf("%d ",temp->data);
//         temp = temp->next;
//     }
// }
// //TO CHECK FOR COMMOM ELEMENTS IN LINKED LIST
// bool isCommom(struct node *head, int data){
//     struct node *temp = head;
//     while(temp!=NULL){
//         if(temp->data == data) return true;
//         temp = temp->next;
//     }
//     return false;
// }
// //UNION OF SETS
// void setUnion(struct node *head1, struct node *head2){
//     struct node *head3= NULL;
//     struct node *temp = head1;
//     while(temp!=NULL){
//         create(&head3,temp->data);
//         temp=temp->next;
//     }
//     temp = head2;
//     while(temp!=NULL){
//         if(!isCommom(head3,temp->data)){
//             create(&head3, temp->data);
//         }
//         temp = temp->next;
//     }
//     display(head3);
// }
// //INTERSECTION OF LISTS
// void setIntersection(struct node *head1, struct node *head2){
//     struct node *head3= NULL;
//     struct node *temp = head1;
//     while(temp!=NULL){
//         if(isCommom(head2, temp->data)){
//             create(&head3,temp->data);
//         }
//         temp = temp->next;
//     }
//     display(head3);
// }
// //MAIN
// int main(){
//     struct node *head1= NULL;
//     printf("\nSET 1: ");
//     int choice1=1;
//     do{
//         int data1;
//         printf("Enter data for set 1: ");
//         scanf("%d",&data1);
//         create(&head1, data1);
//         printf("1->continue 0->stop: ");
//         scanf("%d",&choice1);
//     }while(choice1!=0);
//     display(head1);
//     struct node *head2= NULL;
//     printf("\nSET 2: ");
//     int choice2=1, data2;
//     while(choice2){
//         printf("Enter data for set 2: ");
//         scanf("%d",&data2);
//         create(&head2, data2);
//         printf("1->continue 0->stop: ");
//         scanf("%d",&choice2);
//     }
//     display(head2);
//     printf("\nUNION OF SETS: ");
//     setUnion(head1,head2);
//     printf("\nINTERSECTION OF SETS: ");
//     setIntersection(head1,head2);
// }
//TO PERFORM UNION AND INTERSECTION OF TWO SETS WITH AND WITHOUT HEADER USING DOUBLY LINKED LIST
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node{
    int data;
    struct node *prev;
    struct node *next;
};
//TO CREATE A DOUBLY LINKED LIST
void create(struct node **head, int ele){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = ele;
    newnode->prev = NULL;
    newnode->next = NULL;
    if(*head==NULL){
        newnode->prev = newnode->next = *head = newnode;
    }
    else{
        struct node *temp = *head;
        while(temp->next != *head){
            temp=temp->next;
        }
        newnode->prev = temp;
        newnode->next = temp->next;
        temp->next = newnode;
        (*head)->prev = newnode;
    }
}
//DISPLAY FUNCTION
void display(struct node *head){
    if(head==NULL){
        printf("Empty list");
        return;
    }
    struct node *temp = head;
    while(temp->next!=head){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("%d ",temp->data);
}
//CHECK FOR COMMOM ELEMENTS
int isCommon(struct node *head, int ele){
    struct node *temp = head;
    while(temp->next!=head){
        if(temp->data==ele) return 1;
        temp=temp->next;
    }
    if(temp->data==ele) return 1;
    return 0;
}
//UNION
void setUnion(struct node *head1, struct node *head2){
    struct node *head3 = NULL;
    struct node *temp = head1;
    while(temp->next!=head1){
        create(&head3,temp->data);
        temp=temp->next;
    }
    create(&head3,temp->data);
    temp = head2;
    while(temp->next!=head2){
        if(!isCommon(head3,temp->data)){
            create(&head3,temp->data);
        }
        temp=temp->next;
    }
    create(&head3,temp->data);
    display(head3);
}
//INTERSECTION
void setIntersection(struct node *head1, struct node *head2){
    struct node *head3=NULL;
    struct node *temp1 = head1;
    while(temp1->next!=head1){
        if(isCommon(head2,temp1->data)){
            create(&head3,temp1->data);
        }
        temp1=temp1->next;
    }
    create(&head3,temp1->data);
    display(head3);
}
//MAIN
void main(){
    struct node *head1=NULL;
    printf("\nSet 1: ");
    int choice1=1;
    do{
        int data1;
        printf("Enter data for set 1: ");
        scanf("%d",&data1);
        create(&head1, data1);
        printf("1->continue 0->stop: ");
        scanf("%d",&choice1);
    }while(choice1!=0);
    display(head1);
    struct node *head2= NULL;
    printf("\nSET 2: ");
    int choice2=1, data2;
    while(choice2){
        printf("Enter data for set 2: ");
        scanf("%d",&data2);
        create(&head2, data2);
        printf("1->continue 0->stop: ");
        scanf("%d",&choice2);
    }
    display(head2);
    printf("\nUNION OF SETS: ");
    setUnion(head1,head2);
    printf("\nINTERSECTION OF SETS: ");
    setIntersection(head1,head2);
}