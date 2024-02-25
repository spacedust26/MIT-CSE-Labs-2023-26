//To perform topological sort using source removal technique
//Input - graph
//Output - topological sort order

#include<stdio.h>

int am[100][100];
int indegree[100];

//Source removal technique
void sourceRemoval(int vertices){
	for(int i = 0 ; i < vertices ; i++){
		indegree[i] = 0;
		for(int j = 0 ; j < vertices ; j++){
			indegree[i] += am[j][i];
		}
	}
	for(int i = 0; i < vertices ; i++){
		for(int j = 0; j < vertices ; j++){
			if(indegree[j] == 0){
				printf("%d ",j);
				indegree[j] = -1;
				for(int k = 0 ; k < vertices ; k++){
					if(am[j][k]){
						indegree[k]--;
					}
				}
				break;
			}
		}
	}
}

//Main function
int main(){
	  int vertices;
    printf("Enter total vertices of the graph: ");
    scanf("%d",&vertices);
    printf("Enter adjacency matrix: ");
    for(int i = 0 ; i < vertices ; i++){
        for(int j = 0 ; j < vertices ; j++){
            scanf("%d",&am[i][j]);
        }
    }
		printf("Toplogical Sort: ");
		sourceRemoval(vertices);
		return 0;
}