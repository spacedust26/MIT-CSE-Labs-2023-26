/*Vignesh and his wife Lata are facing a cash crisis. They go to the nearby ATM to get 
some cash. There are 3 ATMs inside the same room. People are standing in queue 
outside, and go inside the room in groups of 3 to the ATMs, fetch their money and 
come out. Lata has an irrational fear in getting money from ATM that her ATM pin 
will somehow be stolen and her money will be lost. So she will always like to go into 
room with Vignesh. Vignesh is standing at position K in line, immediately followed 
by lata (at position K+1). Can you tell whether Vignesh and Lata both will be able to 
get money in such a way that Lata does not feel insecure? Using queue, find whether 
they can get money for the given set of N and K. Input: the first line contains an 
integer T denoting the number of test cases. T test cases follow. The only line of each 
test case contains two spaces separated integers N and K , Where N denotes number 
of people in the queue. And K denotes the position of Vignesh . Constraints 
1<=T<=100 3<=N<=100 1<=K<=N-1, N is divisible by 3.
Sample Input
2
3 1
6 3
Output
Yes 
Page 43 of 95
No*/
#include<stdio.h>
#include<stdlib.h>
#define size 40
typedef struct{
    int a[size];
    int front;
    int rear;
}CQUEUE;
void intilialise(CQUEUE *q){
    q->front = q->rear = -1;
}
int isEmpty(CQUEUE *q){
    if(q->front ==-1 && q->rear ==-1) return 1;
    else return 0;
}
int isFull(CQUEUE *q){
    if((q->rear+1) % size == q->front)return 1;
    else return 0;
}
void enqueue(CQUEUE *q, int ele){
    if(isFull(q)){
        printf("Overflow");
        return;
    }
    if(isEmpty(q)){
        q->rear = q->front = 0;
        q->a[q->rear] = ele;
    }
    else{
        q->rear= (q->rear+1) % size;
        q->a[q->rear] = ele;
    }
}
int dequeue(CQUEUE *q){
    if(isEmpty(q)){
        printf("Underflow");
        return -999;
    }
    int a = q->a[q->front];
    if(q->front == q->rear){
        q->front = q->rear =-1;
    }
    else{
        q->front = (q->front+1)%size;
    }
    return a;
}
int getMoney(int n, int k){
    CQUEUE q;
    intilialise(&q);
    for(int i=1;i<=n;i++){
        enqueue(&q,i);
        if(i%3==0){
            int count=0;
            while(!isEmpty(&q)){
                int person = dequeue(&q);
                count++;
                if(person == k){
                    if(count==1) return 1;
                    else return 0;
                }
            }
        }
    }
    return 0;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,k;
        scanf("%d %d",&n,&k);
        if(getMoney(n,k)) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}