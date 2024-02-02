//Consecutive Integer Checking Algorithm - gcd(m,n)
//Input - two non negative not-both-zero integers
//Output - gcd of m aand n
//Drawback - one of the number can't be zero

#include<stdio.h>

//Consecutive integer checking
int cic(int m , int n){
  int opcount = 0;
  int t = m < n ? m : n;
  while(t != 1){
    opcount++;
    if(m % t == 0){
      if(n % t == 0){
        printf("Opcount = %d\n",opcount);
        return t;
      }
    }
    t--;
  }
  opcount++;
  printf("Opcount = %d\n",opcount);
  return t;
}

//Main function
int main(){
  int m , n;
  printf("Enter m and n: ");
  scanf("%d %d",&m,&n);
  printf("GCD using consecutive integer checking is %d\n",cic(m,n));
  return 0;
}