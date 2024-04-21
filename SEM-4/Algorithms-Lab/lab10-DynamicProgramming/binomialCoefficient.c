//computes C(n,k) using dynamic programming
//input - a pair of non negative integers n>=k>=0
//output - the value of C(n,k)
//Time efficiency - O(nk)
#include<stdio.h>

//minimum function
int min(int a, int b){
  return a<b ? a:b;
}

//compute binomial coeffient
int binomial(int n, int k){
  int c[30][30];
  for(int i = 0 ; i <= n ; i++){
    for(int j = 0; j<= min(i,k) ; j++){
      if(j == 0 || j == i) c[i][j] = 1;
      else c[i][j] = c[i-1][j-1] + c[i-1][j];
    }
  }
  return c[n][k];
}

//Main function
int main(){
  int n,k;
  printf("Enter n, k values: ");
  scanf("%d %d",&n, &k);
  printf("Binomial coefficient : %d", binomial(n,k));
  return 0;
}