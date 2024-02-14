//To sort a given set of integers using quick sort
//Input - an array of intgers
//Output - array sorted in ascending order
//Time complexity - best case : nlogn
//avearge case : 1.39nlogn
//worst case : n^2

#include <stdio.h>
int opcount = 0;
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low + 1;
    for (int j = low + 1; j <= high; j++) {
      opcount++;
        if (arr[j] < pivot) {
            swap(&arr[i], &arr[j]);
            i++; 
        }
    }
    swap(&arr[low], &arr[i - 1]);
    return (i - 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[30], n;
    printf("Enter limit: ");
    scanf("%d",&n);
    printf("Enter elements: ");
    for(int i = 0 ; i < n ; i++){
      scanf("%d",&arr[i]);
    }
    printf("Given array: \n");
    printArray(arr, n);
    quickSort(arr, 0, n - 1);
    printf("Sorted array: \n");
    printArray(arr, n);
    printf("Opcount = %d\n",opcount);
    return 0;
}
