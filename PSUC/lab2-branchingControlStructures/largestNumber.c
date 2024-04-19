//To find the largesst number among 3 given numbers

#include<stdio.h>

int main(){
  int a,b,c;
  int large = 0;
  printf("Enter 3 numbers: ");
  scanf("%d %d %d",&a,&b,&c);
  if(a > b){
    if(a > c) large = a;
    else large = c; 
  }else{
    if(b > c) large = b;
    else large = c;
  }
  printf("Largest of the 3 numbers: %d", large);
  return 0;
}