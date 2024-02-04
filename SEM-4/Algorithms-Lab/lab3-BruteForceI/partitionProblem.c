//Partition problem using brute force
//Input - An array of numbers
//Output - Subsets can equate to a particular sum

#include<stdio.h>
#include<math.h>

//Partition finding
void partition(int *arr, int n){
  int sum = 0;
  for(int i = 0 ;i < n ;i++){
    sum+= arr[i];
  }
  sum /= 2;
  int found = 0;
    for (int i = 0; i < pow(2, n); i++) {
        int current_sum = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                current_sum += arr[j];
            }
        }
        if (current_sum == sum) {
            found = 1;
            printf("Subset with sum %d: ", sum);
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    printf("%d ", arr[j]);
                }
            }
            printf("\n");
        }
    }
    if (!found) {
        printf("No solution found.\n");
    }
}

//Main function
int main(){
  int n, arr[40];
  printf("Enter size: ");
  scanf("%d",&n);
  printf("Enter array elements : ");
  for(int i = 0 ;i < n ; i++){
    scanf("%d",&arr[i]);
  }
  partition(arr,n);
  return 0;
}