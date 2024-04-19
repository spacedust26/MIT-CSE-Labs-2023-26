//Generate primes between 2 given limits
#include<stdio.h>

int main(){
  int low, high;
  printf("Enter lower limit and upper limit: ");
  scanf("%d %d", &low, &high);
  int i, count;
  while(low <= high){
    i = 2;
    count = 1;
    while(i < low){
      if(low % i == 0){
        count = 0; 
        break;
      }
      i++;
    }
    if(count == 1){
      printf("%d ", low);
    }
    low++;
  }
  return 0;
}