//Assignment problem using brute force technique
//Input - Cost matrix and size
//Output - Lowest cost and job assigmnent
//Time efficency - O(n!)

#include<stdio.h>
#include<stdlib.h>

int v, graph[20][20];
int jobs[20];
int mincost = 9999;
int currentcost = 0;
int permutestore[20];

//swap function
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

//permute function
void permuteJobs(int jobs[], int start, int end){
    if(start == end){
        currentcost = 0;
        for(int i = 0 ; i < v ; i++){
            currentcost += graph[i][jobs[i]];
        }
        if(currentcost < mincost){
            mincost = currentcost;
            for(int i = 0 ; i < v ; i++){
                permutestore[i] = jobs[i];
            }
        }
    }else{
        for(int i = start ; i<= end ; i++){
            swap(&jobs[start], &jobs[i]);
            permuteJobs(jobs, start+1, end);
            swap(&jobs[start], &jobs[i]);
        }
    }
}

//Main function
int main(){
    printf("Enter the total number of jobs available: ");
    scanf("%d",&v);
    printf("Enter the cost matrix: ");
    for(int i = 0 ; i < v ; i++){
        for(int j = 0 ; j < v ;j++){
            scanf("%d",&graph[i][j]);
        }
    }
    for(int i = 0 ; i < v ; i++){
        jobs[i] = i;
    }
    permuteJobs(jobs, 0 , v-1);
    printf("\nMinimum cost of assigning jobs : %d\n", mincost);
    for(int i = 0 ; i < v ; i++){
        printf("Person %d - Job %d\n", i+1, permutestore[i] + 1);
    }
}