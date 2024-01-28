/*The students of 2 classes (A and B) are standing in 2 separate lines in ascending order 
of their height. The principle asks the students to combine and join a single line. Write 
a function merge to combine the lines into a single line in ascending order of their 
height using the singly linked list. For example class A: 5->10->15. Class B: 2->3-
>20 resultant line: 2->3->5->10->15->20. Input first line contains 2 integer N1 and 
N2 as number of students of class A and B respectively. Second line contains N1 
integers (heights of the students of class A in ascending order) third line contains N2 
integers (heights of students of class B in ascending order). Output Display Line of 
Class A. Display line of class B. Display the joint class file. 
Sample Input: 
5 4
1 3 4 7 8 
2 5 6 9
Sample Output
Class A
->1->3->4->7->8
Class B
->2->5->6->9
Joint Class 
->1->2->3->4->5->6->7->8->9*/
#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};
//ENTER HEIGHTS IN ASCENDING ORDER
void create(struct node **head, int data){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    static struct node *temp;
    if(*head==NULL){
        *head = temp = newnode;
    }
    else{
        temp->next = newnode;
        temp = newnode;
    }
}
//DISPLAY FUNCTION
void display(struct node *head){
    struct node *temp = head;
    while(temp!=NULL){
        printf("-> %d ",temp->data);
        temp=temp->next;
    }
}
//MERGE THE TWO LINES IN ASCENDING ORDER
void merge(struct node *head1, struct node *head2){
    struct node *head3= NULL;
    struct node *temp1= head1;
    struct node *temp2= head2;
    while(temp1!=NULL && temp2!=NULL){
        while(temp2->data<temp1->data){
            create(&head3,temp2->data);
            temp2=temp2->next;
        }
        create(&head3, temp1->data);
        temp1= temp1->next;
    }
    while(temp1!=NULL){
        create(&head3, temp1->data);
        temp1=temp1->next;
    }
    while(temp2!=NULL){
        create(&head3, temp2->data);
        temp2=temp2->next;
    }
    display(head3);
}
//MAIN
int main(){
    struct node *head1=NULL;
    struct node *head2=NULL;
    int n1,n2,data;
    //CLASS A DATA
    printf("Enter total strength of class A: ");
    scanf("%d",&n1);
    for(int i=0;i<n1;i++){
        printf("Enter student height %d: ",i+1);
        scanf("%d",&data); 
        create(&head1,data);
    }
    printf("Class A: ");
    display(head1);

    //CLASS B DATA
    printf("\nEnter total strength of class B: ");
    scanf("%d",&n2);
    for(int i=0;i<n2;i++){
        printf("Enter student height %d: ",i+1);
        scanf("%d",&data); 
        create(&head2,data);
    }
    printf("Class B: ");
    display(head2);

    //JOINT CLASS
    printf("\nJoint class: ");
    merge(head1,head2);
}