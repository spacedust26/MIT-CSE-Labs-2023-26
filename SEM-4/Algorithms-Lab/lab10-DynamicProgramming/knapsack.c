//0/1 knapsack problem using bottom up apprach dynaimc progarmming
//Input - number of items and their weights and values
//Output - max value and weight
//Time compelxity - O(nw)

#include<stdio.h>
#include<stdlib.h>

int maxi(int a, int b){
  return a > b ? a : b;
}

void knapsack(int n, int *w, int *v, int b){
  int profit[50][50];
  for(int i = 0 ; i <= n ; i++){
    for(int j= 0; j <= b ; j++){
      profit[i][j] = 0;
    }
  }
  for(int i = 1 ; i<=n ; i++){
    for(int j = 1 ; j<=b ; j++){
      if(j - w[i-1] < 0){
        profit[i][j] = profit[i-1][j]; 
      }else{
        profit[i][j] = maxi(profit[i-1][j] , v[i-1] + profit[i-1][j-w[i-1]]);
      }
    }
  }
  printf("\nProfit matrix:\n");
  for(int i = 0 ; i <= n ; i++){
    for(int j = 0 ; j <= b ; j++){
      printf("%d\t",profit[i][j]);
    }
    printf("\n");
  }
  printf("\nMaximum cost: %d\n",profit[n][b]);
  int i = n;
  int j = b;
  printf("Items are: ");
  while(i > 0 && j >= 0){
    if(profit[i][j] > profit[i-1][j]){
      printf("%d ",i);
      j = j - w[i - 1];
    }
    i--;
  }
}

//Main function
int main(){
  int n, b;
  printf("Enter total number of items: ");
  scanf("%d",&n);
  int *w = (int*)calloc(n,sizeof(int));
  int *v = (int*)calloc(n,sizeof(int));
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
  knapsack(n,w,v,b);
}

