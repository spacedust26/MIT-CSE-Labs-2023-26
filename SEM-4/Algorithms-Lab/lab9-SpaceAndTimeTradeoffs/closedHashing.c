//Program to construct a closed hash table
//Input - set of values, hash table size
//Output - hash table, number of successful and unsuccessful comparisons

#include<stdio.h>
#include<stdlib.h>
int *hashArray;
int hashSize;
int comparisons = 0;

//Insert into the hash table
void insert(int ele){
  int i;
  int index = ele % hashSize;
  for(i = 0 ; i < hashSize ; i++){
    int newindex = (index + i) % hashSize;
    if(hashArray[newindex] == -1){
      hashArray[newindex] = ele;
      break;
    }
  }
  if(i == hashSize) printf("\nCannot be inserted.");
}

//Search from a hash table
int search(int ele){
  int index = ele % hashSize;
  for(int i = 0 ; i < hashSize ; i++){
    int newindex = (index + i) % hashSize;
    comparisons++;
    if(hashArray[newindex] == ele) return 1;
  }
  return 0;
}

//Main function
int main(){
  int n, ele;
  printf("Enter hash table size: ");
  scanf("%d",&hashSize);
  hashArray = (int*)calloc(hashSize, sizeof(int));
  for(int i = 0 ; i < hashSize ; i++){
    hashArray[i] = -1;
  }
  printf("Enter the total number of elements: ");
  scanf("%d",&n);
  printf("Enter the elements :");
  for(int i = 0 ; i < n ; i++){
    ele = rand() % (1000 -0 + 1) + 0;
    printf("\nElement %d: %d",i+1, ele);
    insert(ele);
  }
  printf("\nEnter the element to be searched: ");
  scanf("%d",&ele);
  if(search(ele))printf("\nFound");
  else printf("\nNot found");
  printf("\nTotal comparisons: %d", comparisons);
}