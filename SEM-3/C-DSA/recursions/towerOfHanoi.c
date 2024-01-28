#include<stdio.h>
void toh(int n,int a,int b,int c){
  if(n==1){
    printf("move disk from %d to %d\n",a,c);
    return;
  }
  toh(n-1,a,c,b);
  printf("move disk from %d to %d\n",a,c);
  toh(n-1,b,a,c);

}
int main(){
  int n,a=1,b=2,c=3;
  printf("Total disks: ");
  scanf("%d",&n);
  toh(n,a,b,c);
}