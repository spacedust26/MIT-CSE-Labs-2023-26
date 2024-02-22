//Sieve of Erthaosthenes to find prime factors of a number
//Input - an integer n >= 2;
//Output - array L of all prime factors less than or equal to n
//Time complexity - O(n)

#include<stdio.h>
#include<stdlib.h>

//Global variables
int k;

//Sieve of erathothenes
int *soe(int n){
  int *arr = (int *) calloc(n, sizeof(int));
  for(int p = 2 ; p <= n ; p++){
    arr[p] = p;
  }
  for(int p = 2 ; p*p <= n ; p++){
    if(arr[p] != 0){
      int j = p * p;
      while(j <= n){
        arr[j] = 0;
        j = j + p; 
      }
    }
  }
  k = 0;
  int *L = (int *) calloc(n, sizeof(int));
  for(int p = 2 ; p <= n ; p++){
    if(arr[p] != 0){
      L[k++] = arr[p];
    }
  }
  return L;
}

//Main funtion
int main(){
  int n;
  printf("Enter n: ");
  scanf("%d",&n);
  int *arr = soe(n);
  for(int i = 0 ; i < k ; i++){
    printf("%d ",arr[i]);
  }
}