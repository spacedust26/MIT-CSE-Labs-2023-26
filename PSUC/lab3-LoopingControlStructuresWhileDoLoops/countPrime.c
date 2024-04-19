//To count the number of primes and composites until -1 is encountered using do while
#include<stdio.h>

int main(){
  int n, prime = 0, composite = 0, i, count;
  do{
    printf("\nEnter number: ");
    scanf("%d",&n);
    if(n == -1) break;
    i = 2;
    count = 1;
    if(n == 1){
      printf("Neither prime nor composite");
      continue;
    }
    if(n == 2){
      prime++;
      continue;
    }
    do{
      if(n % i == 0){
        count = 0;
        break;
      }
      i++;
    }while(i < n);
    if(count == 1) prime++;
    else composite++;
  }while(1);
  printf("Primes = %d\nComposites = %d", prime, composite);
  return 0;
}