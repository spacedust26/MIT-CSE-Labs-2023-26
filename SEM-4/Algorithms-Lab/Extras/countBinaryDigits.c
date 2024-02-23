//To count the number of binary digits in a number
//Input - positive integer n
//Output - The number of binary digits in n's binary representaion
//Time complexity - O(log n)

#include<stdio.h>

//Counting binary digits function
int count(int n){
  int count = 1;
  while(n > 1){
    n/=2;
    count++;
  }
  return count;
}

//Main function
int main(){
  int n;
  printf("Enter number: ");
  scanf("%d",&n);
  printf("The number of binary digits is %d",count(n));
}