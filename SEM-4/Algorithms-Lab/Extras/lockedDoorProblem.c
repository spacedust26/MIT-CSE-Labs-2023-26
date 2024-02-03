//There are n closed lockers in a hallway, numbered sequentially from 1 to n. Toggle the door of every ith locker: if the door is closed, you open it; if it is open, you close it. After the last pass, which locker doors are open and which are closed? How many of them are open?
//Input - natural number n
//Output - list and number of open doors and closed doors

#include<stdio.h>
#include<stdlib.h>

//Toggle function
void toggle(int n){
  int arr[n], closed[n], open[n];
  int c=0, o=0;
  for(int i = 1 ;i<= n ;i++){
    arr[i] = -1;//close
  }
  for(int i = 1; i <= n ; i++){
    int j = i;
    while(j <= n){
      if(arr[j] == -1) arr[j] = -2; //open
      else arr[j] = -1; //close 
      j = j + i;
    }
  }
  int i;
  for(i = 1 ; i<= n ;i++){
    if(arr[i]== -1) closed[c++] = i;
    else open[o++] = i;
  }
  printf("Total open doors: %d\n",o);
  for(int i =0 ; i<o ;i++){
    printf("%d ",open[i]);
  }
  printf("\n");
   printf("Total closed doors: %d\n",c);
  for(int i =0 ; i<c ;i++){
    printf("%d ",closed[i]);
  }
}

//Main function
int main(){
  int n;
  printf("Enter n: ");
  scanf("%d",&n);
  toggle(n);
}