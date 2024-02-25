//To sort a given set of integers using merge sort
//Input - an array of intgers
//Output - array sorted in ascending order
//Time complexity - nlogn
#include <stdio.h>

//merge 
void merge(int *arr, int lb, int mid, int ub){
	int i = lb;
	int j = mid + 1;
	int k = lb;
	int barr[50];
	while(i <= mid && j <= ub){
		if(arr[i] < arr[j]){
			barr[k++] = arr[i++];
		}else{
			barr[k++] = arr[j++];
		}
	}
	if(i > mid){
		while(j <= ub){
			barr[k++] = arr[j++];
		}
	}else{
		while(i <= mid){
			barr[k++] = arr[i++];
		}
	}
	for(int k = lb ; k <= ub ; k++){
		arr[k] = barr[k]; 
	}
}

//mergesort
void mergesort(int *arr, int lb, int ub){
	if(lb < ub){
		int mid = (lb + ub)/2;
		mergesort(arr, lb, mid);
		mergesort(arr, mid+1, ub);
		merge(arr, lb, mid, ub);
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
    mergesort(arr, 0 , n-1);
    for(int i = 0 ; i < n ; i++){
        printf("%d ",arr[i]);
    }
    return 0;
}