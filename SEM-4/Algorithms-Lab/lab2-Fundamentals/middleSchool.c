//Middle School Procedure - gcd(m,n)
//Input - two non negative not-both-zero integers
//Output - gcd of m and n
//Time complexity - O(nlogn)

#include<stdio.h>
#include<stdlib.h>

//Approach 1 - normal prime factorisation
int msm1(int m , int n){
  int gcd = 1;
  for(int i = 2; i <= m && i <=n; i++){
    while(m % i == 0 && n % i == 0){
      gcd *= i;
      m /= i;
      n /= i;
    }
  }
  return gcd;
}

//Approach 2 - using seive of erathosthenes

//Global variable
int k = 0;
int *sieve(int n){
  int opcount = 0;
  int *arr = (int *)calloc(n, sizeof(int));
  for(int p=2; p<=n ;p++){
    arr[p] = p;
  }
  for(int p=2 ; p*p<=n; p++){
    if(arr[p] != 0){
      int j = p*p;
      while(j<= n){
        arr[j] = 0;
        j = j+p;
        opcount++;
      }
    }
  }
  k = 0;
  int *L = (int *)calloc(n, sizeof(int));
  for(int p=2 ; p<=n ; p++){
    if(arr[p] != 0){
      L[k++] = arr[p];
    }
  }
  printf("Opcount = %d\n",opcount);
  return L;
}
int msm2(int m, int n){
  int min = m < n ? m : n;
  int *arr = sieve(min);
  int gcd = 1;
  for(int i = 0; i< k ; i++){
    while(m % arr[i]==0 && n% arr[i]==0){
      gcd *= arr[i];
      m /= arr[i];
      n /= arr[i];
    }
  }
  return gcd;
}

//Main function
int main(){
  int m,n;
  printf("Enter m and n: ");
  scanf("%d %d",&m,&n);
  printf("GCD using prime factorisation is %d\n",msm1(m,n));
  printf("GCD using prime factorisation using seive of erathothenes is %d\n",msm2(m,n));
}