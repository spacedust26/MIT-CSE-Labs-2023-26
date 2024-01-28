/*Given an array arr with n elements and a number k, k<n. The task is to delete k
elements which are smaller than next element (i.e., we delete arr[i] if arr[i] <
arr[i+1]) or become smaller than next because next element is deleted. Example:
Input: arr[] = {20, 10, 25, 30, 40}, k = 2
Output: 25 30 40
Explanation: First we delete 10 because it follows arr[i] < arr[i+1]. Then we delete 20
because 25 is moved next to it and it also starts following the condition.*/
//stack implementation using arrays
#include<stdio.h>
#include<stdlib.h>
#define size 40
typedef struct{
    int a[size];
    int top;
}STACK;
void initialize(STACK *s){
    s->top=-1;
}
int isEmpty(STACK *s){
    if(s->top==-1)return 1;
    else return 0;
}
int isFull(STACK *s){
    if(s->top==size-1) return 1;
    else return 0;
}
void push(STACK *s, int ele){
    if(!isFull(s)) s->a[++s->top] = ele;
    else printf("Overflow");
}
int pop(STACK *s){
    if(!isEmpty(s)) return s->a[s->top--];
    else{
        printf("Underflow");
        return -26;
    }
}
void display(STACK *s){
    for(int i=0;i<=s->top;i++){
        printf("%d ",s->a[i]);
    }
}
void deletek(STACK *s, int a[size], int n, int k){
    int i, result[size], j=0;
    for(i=0;i<n;i++){
        while(!isEmpty(s) && k > 0 && (a[i]> s->a[s->top] )){
            pop(s);
            k--;
        }
        push(s,a[i]);
    }
    printf("Output: ");
    while(!isEmpty(s)){
        result[j++]=pop(s);
    }
    for(int i = j-1 ;i>=0;i--){
        printf("%d ",result[i]);
    }
}
int main(){
    STACK s;
    initialize(&s);
    int n,k,a[size];
    printf("Enter n: ");
    scanf("%d",&n);
    printf("Enter k: ");
    scanf("%d",&k);
    printf("Enter array elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    deletek(&s,a,n,k);
}

