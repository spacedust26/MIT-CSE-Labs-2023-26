//Write a program to find GCD using middle school method using sieve of erathosthenes
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int *sieve(int n, int *size){
  int *arr = (int*)calloc(n+1, sizeof(int));
  int opcount = 0;
  for(int i=2;i<=n;i++){
    arr[i] = i;
  }
  for(int i=2; i <= sqrt(n) ;i++){
    if(arr[i]!=0){
      int j = i*i;
      while(j<=n){
        opcount++;
        arr[j] = 0;
        j=j+i;
      }
    }
  }
  int k=0;
  int *finalArr = (int*)calloc(n+1, sizeof(int));
  for(int i=2;i<=n;i++){
    if(arr[i]!=0){
      finalArr[k++] = arr[i];
    }
  }
  printf("Opcount = %d",opcount);
  *size=k;
  return finalArr;
}

int isPrime(int n){
  if(n < 2) return 0;
  for(int i=2 ; i<= sqrt(n) ;i++){
    if(n%i==0) return 0;
  }
  return 1;
}
int msm(int m, int n){
  int size;
  int max = m > n ? m : n;
  int *arr = sieve(max, &size);
  int gcd =1;
  for(int i=0;i<size;i++){
    while(m%arr[i]==0 && n%arr[i]==0){
      gcd *= arr[i];
      m /= arr[i];
      n /= arr[i];
    }
  }
  return gcd;
}
int main(){
  int m,n;
  printf("Enter two numbers: ");
  scanf("%d %d",&m,&n);
  printf("\nGCD using Middle School algorithm: %d",msm(m,n));
}


