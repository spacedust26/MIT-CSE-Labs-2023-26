//Implement a graph using adjacency  matrix representation
//Input - number of vertices and possible edges
//Output - adjacency matrix
//Time complexity - O(n^2)

#include<stdio.h>

int am[30][30];

//Adjacency matrix function
void adjacencyMatrix(int s, int d, int vertices, int am[30][30]){
  //Undirected graph
  if(s>=0 && s<vertices && d>=0 && d<vertices){
    am[s][d] = 1;
    am[d][s] = 1;
  }else printf("Invalid position");

  //directed graph
  // if(s>=0 && s<vertices && d>=0 && d<vertices){
  //   am[s][d] = 1;
  // }else printf("Invalid position");
}

//Print matrix
void print(int am[30][30], int vertices){
  for(int i = 0 ; i < vertices ; i++){
    for(int j = 0 ; j < vertices ; j++){
      printf("%d\t",am[i][j]);
    }
    printf("\n");
  }
}

//Main function
int main(){
  int vertices;
  int s,d;
  printf("Enter total vertices: ");
  scanf("%d",&vertices);
  int choice;
  do{
    printf("Enter source and destination vertices: ");
    scanf("%d %d",&s,&d);
    adjacencyMatrix(s,d,vertices,am);
    printf("1->continue 0->stop: ");
    scanf("%d",&choice);
  }while(choice==1);
  print(am,vertices);
}