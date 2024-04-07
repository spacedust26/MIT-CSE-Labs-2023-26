//To sort a given set of integers using quick sort
//Input - an array of intgers
//Output - array sorted in ascending order
//Time complexity - best case : nlogn
//avearge case : 1.39nlogn
//worst case : n^2

#include<stdio.h>

int inversions = 0;

//Swap function
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

//Partition function
int partition(int *arr, int lb, int ub){
    int pivot = arr[lb];
    int start = lb;
    int end = ub;
    while(start < end){
        while(arr[start] <= pivot && start <= ub){
            start++;
        }
        while(arr[end] > pivot && end >= lb){
            end--;
        }
        if(start < end){
            inversions++;
            swap(&arr[start], &arr[end]);
        }
    }
    swap(&arr[lb], &arr[end]);
    return end;
}

//Quicksort function
void quicksort(int *arr, int lb, int ub){
    if(lb < ub){
        int loc = partition(arr, lb, ub);
        quicksort(arr, lb, loc-1);
        quicksort(arr, loc+1, ub);
    }
}

//Main function
int main(){
    int n, arr[30];
    printf("Enter array size: ");
    scanf("%d",&n);
    printf("Enter array elements: ");
    for(int i = 0 ; i < n ; i++){
        scanf("%d",&arr[i]);
    }
    quicksort(arr, 0 , n-1);
    for(int i = 0 ; i < n ; i++){
        printf("%d ",arr[i]);
    }
    printf("\nTotal number of inversions: %d",inversions);
    return 0;
}