//To implement travelling salesman problem using brute force
//Input - total number of cities and distance matrix
//Output - least distance to cover all the cities
//Time complexity - O(n!)

#include <stdio.h>

//swap function
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int minpath = 9999;
int currentpath = 0;
int v, graph[10][10];

//Generating permuations
void permutepath(int path[], int start, int end){
    if(start == end){
        currentpath = 0;
        for(int i = 0 ; i < v - 1; i++){
            currentpath += graph[path[i]][path[i+1]];
        }
        currentpath += graph[path[v-1]][path[0]];//cost of returning back
        if(currentpath < minpath){
            minpath = currentpath;
        }
    }else{
        for(int i = start ; i<= end ; i++){
            swap(&path[start], &path[i]);
            permutepath(path,start+1,end);
            swap(&path[start], &path[i]);
        }
    }
}

// Main function
int main(){
    printf("Enter number of cities: ");
    scanf("%d", &v);
    printf("Enter the distance matrix: ");
    for(int i = 0; i < v; i++){
        for (int j = 0; j < v; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    int path[10];
    for(int i = 0 ; i < v ; i++){
        path[i] = i;
    }
    permutepath(path,0,v-1);
    printf("Minimum distance to cover all cities: %d\n",minpath);
    return 0;
}
