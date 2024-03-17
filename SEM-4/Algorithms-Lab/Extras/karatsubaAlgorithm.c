//Implement large integer multiplication using Karatsuba's algorithm
//Input - two large integers
//Output - product of the integers
//Time complexity - O(n^1.58)
//HAS ERROR


#include<stdio.h>
#include<math.h>

//maximum function
long int maximum(long int x, long int y){
  return x > y ? x : y;
}

// Length of number function
int length(long int x) {
    if (x == 0) return 1;
    int count = 0;
    while (x > 0) {
        x /= 10;
        count++;
    }
    return count;
}

//Karatsuba's algorithm
long int karatsuba(long int x, long int y){
  if(x < 10 || y < 10) return x * y;
  else{
    int n = maximum(length(x), length(y));
    int half = n / 2;
    long int a = x / (long int)(pow(10, half)); //left part of x
    long int b = x % (long int)(pow(10, half)); //right part of x
    long int c = y / (long int)(pow(10, half)); //left part of y
    long int d = y % (long int)(pow(10, half)); //right part of y
    long int ac = karatsuba(a,c);
    long int bd = karatsuba(b,d);
    long int ad_plus_bc = karatsuba(a+b, c+d)-ac-bd;
    return (ac * (long int)(pow(10, 2*half))) + (ad_plus_bc * (long int)(pow(10, half))) + (bd);
  }
}

//Main function
int main(){
  long int x, y;
  printf("Enter two large integers: ");
  scanf("%ld %ld",&x,&y);
  printf("Product: %ld\n", karatsuba(x,y));
  return 0;
}
