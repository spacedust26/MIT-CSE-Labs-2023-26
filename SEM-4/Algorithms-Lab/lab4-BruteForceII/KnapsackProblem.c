//Knapsack problem using brute force design technique to determine the knapsack for a capacity b
//Input - An array w[0, n-1] of weights, v[0, n-1] of values, capacity b, total items n
//Output - An array k[0, m-1] of knapsack items
//Time complexity - O(2^n)

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//Global variables
int max;

//Knapsack function
int knapsack(int *w, int *v, int n, int b){
  int index=0;
  max = 0;
  for(int i = 0 ; i < pow(2,n) ; i++){
    int weight = 0;
    int value = 0;
    for(int j = 0 ; j < n ; j++){
      if(i & (1 << j)){
        weight += w[j];
        value += v[j];
      }
    }
    if(weight <= b && value > max){
      max = value;
      index = i;
    }
  }
  printf("Maximum value: %d", max);
  return index;
}

//Main function
int main(){
  int n, b;
  int *w = (int*)calloc(n,sizeof(int));
  int *v = (int*)calloc(n,sizeof(int));
  printf("Enter total number of items: ");
  scanf("%d",&n);
  printf("Enter weights for\n");
  for(int i = 0 ; i < n ; i++){
    printf("item %d: ",i+1);
    scanf("%d",&w[i]);
  }
  printf("Enter values for\n");
  for(int i = 0 ; i < n ; i++){
    printf("item %d: ",i+1);
    scanf("%d",&v[i]);
  }
  printf("Enter knapsack weight capacity: ");
  scanf("%d",&b);
  int knap = knapsack(w,v,n,b);
  printf("\nArray of knapsack items:\n");
  for(int j = 0 ; j < n ; j++){
    if(knap & (1 << j)){
      printf("Item %d: weight %d value %d\n", j+1, w[j], v[j]);
    }
  }
  free(w);
  free(v);
}
