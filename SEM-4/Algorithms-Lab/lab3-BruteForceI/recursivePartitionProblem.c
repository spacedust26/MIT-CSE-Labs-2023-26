//Implement solution to partition proble using recursion
//Input - set of elements and their size
//Ouput - partition set

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int n, set[100];
bool partitionFound = false;

void printPartition(int partition[], int size){
    printf("Partition 1: ");
    for (int i = 0; i < n; i++) {
        if (partition[i] == 1)
            printf("%d ", set[i]);
    }
    printf("\nPartition 2: ");
    for (int i = 0; i < n; i++) {
        if (partition[i] == 0)
            printf("%d ", set[i]);
    }
    printf("\n");
}

bool isSubsetSum(int sum, int index, int partition[]){
  if(sum == 0){
    printPartition(partition, n);
    partitionFound = true;
    return true;
  }
  if(index >= n || sum < 0) return false;
  partition[index] = 1;
  if(isSubsetSum(sum-set[index], index +1, partition)) return true;
  partition[index] = 0;
  return isSubsetSum(sum, index+1, partition);
}

bool canPartition(){
  int totalsum = 0;
  for(int i = 0 ; i < n ; i++){
    totalsum += set[i];
  }
  if(totalsum % 2 != 0) return false;
  int partition[100] = {0};
  return isSubsetSum(totalsum/2, 0, partition);
}

//Main function
int main(){
  printf("Enter set size: ");
  scanf("%d",&n);
  printf("Enter set elements: ");
  for(int i = 0 ; i < n ; i++){
    scanf("%d",&set[i]);
  }
  if(canPartition()){
    if(!partitionFound){
      printf("Partition is possible, but no subsets found.\n");
    }else{
      printf("Partition is not possible.");
    }
  }
}