#include<stdio.h>
int mul(int a, int b){
  if(b==1)return a;
  else return a+mul(a,b-1);
}
int main(){
  int n,m;
  printf("Enter n * m values : ");
  scanf("%d %d",&n,&m);
  printf("Multiplication result: %d",mul(n,m));
}