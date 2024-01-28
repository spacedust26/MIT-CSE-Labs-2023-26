//TO IMPLEMENT A CIRCULAR LINKED LIST
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
//CREATE A CIRCULAR LINKED LIST USING HEAD NODE
void createHead(struct node **head){
    struct node *temp ;
    int c=1;
    do{
        struct node *newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d",&newnode->data);
        newnode->next = NULL;
        if(*head==NULL){
            *head = temp = newnode;
        }
        else{
            temp->next = newnode;
            temp=newnode;
        }
        printf("1->continue 0->stop: ");
        scanf("%d",&c);
    }while(c);
    temp->next = *head;
}
// DISPLAY (HEAD)
void displayHead(struct node *head){
    printf("\nDisplay: ");
    if(head==NULL){
        printf("Empty linked list");
        return;
    }
    struct node *temp = head;
    while(temp->next != head){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("%d ",temp->data);
}
//CREATE A CIRCULAR LINKED LIST USING TAIL NODE
void createTail(struct node **tail){
    int c=1;
    do{
        struct node *newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d",&newnode->data);
        newnode->next = NULL;
        if(*tail==NULL){
            *tail= newnode;
            (*tail)->next = newnode;
        }
        else{
            newnode->next = (*tail)->next;
            (*tail)->next = newnode;
            *tail = newnode;
        }
        printf("1->continue 0->stop: ");
        scanf("%d",&c);
    }while(c);
}
//DISPLAY(TAIL)
void displayTail(struct node *tail){
    printf("\nDisplay: ");
    if(tail==NULL){
        printf("Empty linked list");
        return;
    }
    struct node *temp = tail->next;
     do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != tail->next );
}
//LENGTH OF LINKED LIST
int length(struct node *tail){
    int count=0;
    if(tail==NULL)return 0;
    else{
        struct node *temp = tail->next;
     do {
       count++;
        temp = temp->next;
    } while (temp != tail->next );
    }
    return count;
}
//INSERT FRONT USING TAIL
void insertTailFront(struct node **tail){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter element to be inserted front: ");
    scanf("%d",&newnode->data);
    if(*tail==NULL){
        *tail = newnode;
        newnode->next = *tail;
    }
    else{
        newnode->next = (*tail)->next;
        (*tail)->next = newnode;
    }
}
//INSERT AT THE END USING TAIL
void insertTailEnd(struct node **tail){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter element to be inserted last: ");
    scanf("%d",&newnode->data);
    if(*tail==NULL){
        *tail = newnode;
        newnode->next = *tail;
    }
    else{
        newnode->next = (*tail)->next;
        (*tail)->next  = newnode;
        *tail = newnode;
    }
}
//INSERT AT A GIVEN POSITION USING TAIL
void insertTailPosition(struct node **tail){
    int pos,i=1;
    printf("\nEnter the positon to enter data: ");
    scanf("%d",&pos);
    if(pos<0 || pos>length(*tail)){
        printf("Invalid position");
        return;
    }
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data to be inserted at the %d position: ",pos);
    scanf("%d",&newnode->data);
    if(pos ==0){
        insertTailFront(tail);
    }
    if(pos == length(*tail)){
        insertTailEnd(tail);
    }
    else{
        struct node *temp = (*tail)->next;
        while(i<pos){
            temp=temp->next;
            i++;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
}
//DELETE FROM THE BEGINNING
void deleteTailFront(struct node **tail){
    if(*tail==NULL){
        printf("Empty circular linked list");
        return;
    }
    printf("\nFirst element deleted");
    struct node *temp = (*tail)->next;
    if(temp->next == temp){
        *tail=NULL;
        free(temp);
    }
    else{
        (*tail)->next = temp->next;
        free(temp);
    }
}
//DELETE FROM THE END
void deleteTailEnd(struct node **tail){
    if(*tail==NULL){
        printf("Empty circular linked list");
        return;
    }
    printf("\nLast element deleted");
    struct node *temp =(*tail)->next;
    struct node *prev;
    if(temp == temp->next){
        *tail = NULL;
        free(temp);
    }
    else{
        while(temp->next!= (*tail)->next){
            prev = temp;
            temp=temp->next;
        }
        prev->next = (*tail)->next;
        *tail = prev;
        free(temp);
    }
}
//DELETE FROM A GIVEN POSITION USING TAIL
void deleteTailPosition(struct node **tail){
     if(*tail==NULL){
        printf("\nEmpty circular linked list");
        return;
    }
    int pos,i=1;
    printf("\nEnter the position to be deleted: ");
    scanf("%d",&pos);
    if(pos<0 || pos>length(*tail)){
        printf("Invalid position");
        return;
    }
    printf("Element at %d positon deleted",pos);
    if(pos==0){
        deleteTailFront(tail);
    }
    else if(pos==length(*tail)){
        deleteTailEnd(tail);
    }
    else{
        struct node *temp = (*tail)->next;
        struct node *prev;
        while(i<=pos){
            prev =temp;
            temp= temp->next;
            i++;
        }
        prev->next = temp->next;
        free(temp);
    }
}
//MAIN
int main(){
    //struct node *head= NULL;
    struct node *tail = NULL;
    createTail(&tail);
    displayTail(tail);
    printf("\nNumber of nodes: %d\n",length(tail));
    insertTailFront(&tail);
    displayTail(tail);
    insertTailEnd(&tail);
    displayTail(tail);
    insertTailPosition(&tail);
    displayTail(tail);
    deleteTailFront(&tail);
    displayTail(tail);
    deleteTailEnd(&tail);
    displayTail(tail);
    deleteTailPosition(&tail);
    displayTail(tail);
}