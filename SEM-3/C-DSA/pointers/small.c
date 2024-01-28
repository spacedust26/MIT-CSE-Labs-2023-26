#include<stdio.h>
int main(){
  int a[5]= {14,6,1,3,8};
  int *psm;
  int *pwalk;
  int *plast = a+5-1;
  for(psm=a,pwalk=a+1;pwalk<plast;pwalk++){
    if(*pwalk<*psm){
      psm = pwalk;
    }
  }
  printf("small: %d",*psm);
}