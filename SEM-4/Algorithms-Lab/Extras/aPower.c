//To find the value of a^n using divide and conquer technique
//Input - base and exponent
//output - base^exponent
//Time complexity - O(log n)

#include<stdio.h>
#include<math.h>

int power(int b, int e){
  if(e == 0) return 1;
  else{
   int temp = pow(b, e/2);
   if(e%2==0) return temp*temp;
   else return b*temp*temp;
  }
}

int main(){
  int b,e;
  printf("Enter base and exponent: ");
  scanf("%d %d",&b, &e);
  int result = power(b, e);
  printf("base^exponent = %d",result);
}