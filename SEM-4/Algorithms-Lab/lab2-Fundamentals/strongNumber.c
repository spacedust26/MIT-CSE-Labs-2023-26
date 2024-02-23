//To delete strong numbers from an array using recursion (Strong number = sum of factorial of the number Ex: 145, 2)
//Input - An array of elements
//Output - An array of elements without strong numbers

#include<stdio.h>
#include<stdbool.h>

//Factorial recursive function
int fact(int n){
  if(n==0) return 1;
  else return n * fact(n-1);
}

//Strong number function
bool strong(int n){
  int rd, sum = 0;
  int num = n;
  while(n > 0){
    rd = n % 10;
    sum += fact(rd);
    n /= 10;
  }
  return num == sum;
}

//Array deletion
int delete(int *arr, int n){
  int i = 0;
  while(i < n){
    if(strong(arr[i])){
      int j = i;
      while(j < n - 1){
        arr[j] = arr[j+1];
        j++;
      }
      n--;
    }
    else i++;
  }
  return n;
}

//Main function
void main(void){
  int n, arr[40];
  printf("Enter size: ");
  scanf("%d",&n);
  printf("Enter array elements :");
  for(int i = 0 ; i < n ; i++){
    scanf("%d",&arr[i]);
  }
  int size = delete(arr, n);
  for(int i = 0 ; i < size ; i++){
    printf("%d ",arr[i]);
  }
}