//TO IMPLEMENT A RAGGED ARRAY
#include<stdio.h>
#include<stdlib.h>
int main(){
  int row,i,column,j;
  printf("Enter number of rows: ");
  scanf("%d",&row);
  int **a = (int **)calloc(row+1,sizeof(int*));
  for(i=0;i<row;i++){
    printf("Enter size of row %d: ",i+1);
    scanf("%d",&column);
    a[i]=(int *)calloc(column+1,sizeof(int));
    a[i][0]=column;
    printf("Enter elements for row %d: ",i+1);
    for(j=1;j<=column;j++){
      scanf("%d",&a[i][j]);
    }
  }
  a[i] = NULL;
  for(int i=0;i<row;i++){
    for(int j=0;j<=a[i][0];j++){
      printf("%d ",a[i][j]);
    }
    printf("\n");
  }
}