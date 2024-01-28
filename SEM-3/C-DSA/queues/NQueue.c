/*Design a data representation sequentially mapping n queues into a single array
A(1:m). Represent each queue as a circular queue within A. Write algorithms ADDQ,
DELETEQ and QUEUE-FULL for this representation. Illustrate the working with a
menu driven program.*/
#include<stdio.h>
#include<stdlib.h>
#define SIZE 50
int arr[SIZE];
int front[SIZE];
int rear[ SIZE];
int size[SIZE];
void initialize(int TotalQueue){
    for(int i=0;i<TotalQueue ;i++){
        front[i]=-1;
        rear[i]=-1;
        size[i]=0;
    }
}
int QueueFull(int QueueNum, int ArrayNum){
    if((rear[QueueNum]+1)% ArrayNum == front[QueueNum] && size[QueueNum] == ArrayNum)return 1;
    else return 0;
}
void AddQ(int QueueNum, int ele, int ArrayNum){
    if(QueueFull(QueueNum, ArrayNum)){
        printf("Overflow");
        return;
    }
    if(front[QueueNum]==-1 && rear[QueueNum]==-1){
        front[QueueNum]= rear[QueueNum] = 0;
        arr[rear[QueueNum]] = ele;
        size[QueueNum]++;
    }
    else{
        rear[QueueNum] = (rear[QueueNum] + 1) % ArrayNum;
        arr[rear[QueueNum]] = ele;
        size[QueueNum]++;
    }
}
void DeleteQ(int QueueNum, int ArrayNum){
    if(front[QueueNum] == -1){
        printf("Underflow");
        return;
    }
    printf("Delete: %d",arr[front[QueueNum]]);
    if(rear[QueueNum] == front [QueueNum]){
        rear[QueueNum] = front[QueueNum] = -1;
        size[QueueNum]--;
    }
    else{
        front[QueueNum] = (front[QueueNum]+1)% ArrayNum;
        size[QueueNum]--;
    }
}
int main(){
    int TotalQueue, ArrayNum;
    printf("Enter the number of queues: ");
    scanf("%d",&TotalQueue);
    printf("Enter the Array limit: ");
    scanf("%d", &ArrayNum);
    initialize(TotalQueue);
    int choice=0;
    while(choice!=4){
        printf("\n1.Add 2.Delete 3.QueueFull 4.Exit: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:{
                int ele,QueueNum;
                printf("Enter Queue Number to add to: ");
                scanf("%d",&QueueNum);
                printf("Enter element to add: ");
                scanf("%d",&ele);
                AddQ(QueueNum, ele , ArrayNum);
                break;
            }
            case 2: {
                int QueueNum;
                printf("Enter Queue number to delete from: ");
                scanf("%d",&QueueNum);
                DeleteQ(QueueNum, ArrayNum);
                break;
            }
            case 3:{
                int QueueNum;
                printf("Enter Queue number to check if full: ");
                scanf("%d",&QueueNum);
                if(QueueFull(QueueNum, ArrayNum))printf("Full");
                else printf("Not full");
                break;
            }
            default:{
                break;
            }
        }
    }
}