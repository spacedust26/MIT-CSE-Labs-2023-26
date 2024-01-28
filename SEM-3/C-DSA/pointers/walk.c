//TO PRINT ARRAY MEMBERS FORWARD AND BACKWARD
#include<stdio.h>
int main(){
  int a[5]={1,2,3,4,5};
  int *pf = a;
  int *pl = a+4;
  printf("Forward: ");
  for(int *pwalk=pf;pwalk<=pl;pwalk++){
    printf("%d ",*pwalk);
  }
  printf("\nBackward: ");
  for(int *pwalk=pl;pwalk>=pf;pwalk--){
    printf("%d ",*pwalk);
  }
}