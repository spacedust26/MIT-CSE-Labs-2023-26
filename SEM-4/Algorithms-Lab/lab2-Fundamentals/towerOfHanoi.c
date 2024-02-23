//Implementation of the tower of hanoi puzzle
//Input - Number of discs
//Ouput - Information on moves
//Time complexity - O(2^n)

#include<stdio.h>
int count = 0;

//Tower of hanoi function
void toh(int n , int a , int b, int c){
  if(n == 1){
    count++;
    printf("Move disc from %d to %d\n",a,c);
    return;
  }
  toh(n-1,a,c,b);
  printf("Move disc from %d to %d\n",a,c);
  count++;
  toh(n-1,b,a,c);
}

//Main function
int main(){
  int n, a=1, b=2, c=3;
  printf("Enter the number of discs: ");
  scanf("%d",&n);
  toh(n,a,b,c);
  printf("Total number of moves: %d",count);
  return 0;
}