//Generate a multiplication table for n numbers upto k terms using nested for loop
#include<stdio.h>

int main(){
  int n, k;
  printf("How many numbers ? ");
  scanf("%d",&n);
  printf("Upto how many terms? ");
  scanf("%d",&k);
  for(int i = 1 ; i <= n ; i++){
    for(int j = 1 ; j <= k ; j++){
      printf("%d ", i*j);
    }
    printf("\n");
  }
  return 0;
}