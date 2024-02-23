//To implement  solution  to  partition  problem  using  brute-force technique
//Input - an array of numbers
//Output - two disjoint sets such that the sum of the elements in the first set is equal to the second set
//Time complexity O(n2^n)

#include<stdio.h>
#include<math.h>

//Global variables
int powerSet[100][100];
int totalSubsets;

//Function to generate power set
void generatePowerSet(int arr[], int n){
  //Compute the required sum
  int requiredSum = 0;
  for(int i = 0 ; i < n ; i++){
    requiredSum += arr[i];
  }
  requiredSum /= 2;

  //Generate power set
  int flag = 0;
  totalSubsets = pow(2,n); // or 1 << n
  for(int i = 0 ; i < totalSubsets ; i++){
    int sum = 0;
    for(int j = 0 ; j < n ; j++){
      if(i & (1 << j)){ // check if jth bit in i is set
        powerSet[i][j] = arr[j];
        sum += arr[j];
      }
    }
    if(sum == requiredSum){
      flag = 1;
      printf("{");
      for(int j = 0 ; j < n ; j++){
        if(i & (1 << j)){
          printf("%d ",arr[j]);
        }
      } 
      printf("}\n");
    }
  }
  if(!flag){
    printf("\n No set.");
  }
}

//Main function
int main(){
  int n, arr[100];
  printf("Enter set limit:  ");
  scanf("%d",&n);
  printf("Enter set elements: ");
  for(int i = 0 ; i < n ; i++){
    scanf("%d",&arr[i]);
  }
  generatePowerSet(arr, n);
}