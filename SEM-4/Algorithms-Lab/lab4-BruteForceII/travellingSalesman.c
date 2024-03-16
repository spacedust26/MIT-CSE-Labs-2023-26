//To implement travelling salesman problem using brute force
//Input - total number of cities and distance matrix
//Output - least distance to cover all the cities
//Time complexity - O(n!)

#include <stdio.h>

// Minimum function
int min(int a, int b){
    return (a < b) ? a : b;
}

// Permutation function
int permutation(int perm[10], int n){
    int k, l;
    // Find pivot to modify to get the next lexicographically larger permutation
    for(k = n - 2; k >= 0; k--){
        if (perm[k] < perm[k + 1]) break;
    }
    // If array is in descending order, reset it
    if(k < 0){
        for (int i = 0; i < n; i++){
            perm[i] = i;
        }
        return 0; // No more permutations
    }else{ // Replace the pivot
        for (l = n - 1; l > k; l--) {
            if (perm[k] < perm[l]) break;
        }
        int temp = perm[k];
        perm[k] = perm[l];
        perm[l] = temp;
        // Reverse suffix to obtain lexicographically smallest permutation of the suffix
        for(int i = k + 1, j = n - 1; i < j; i++, j--){
            temp = perm[i];
            perm[i] = perm[j];
            perm[j] = temp;
        }
        return 1; // Next permutation exists
    }
}

// Function to find the shortest path using brute force approach
int tsp(int graph[10][10], int v){
    int perm[10];
    for (int i = 0; i < v - 1; i++) {
        perm[i] = i + 1;
    }
    int min_path = 99999;
    do{
        int current_pathweight = 0;
        // Calculate current path weight
        int k = 0;
        for (int i = 0; i < v - 1; i++) {
            current_pathweight += graph[k][perm[i]];
            k = perm[i];
        }
        current_pathweight += graph[k][0];
        // Update minimum path weight
        min_path = min(min_path, current_pathweight);
    }while(permutation(perm, v - 1));
    return min_path;
}

// Main function
int main(){
    int v, graph[10][10];
    printf("Enter number of cities: ");
    scanf("%d", &v);
    printf("Enter the distance matrix: ");
    for(int i = 0; i < v; i++){
        for (int j = 0; j < v; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    printf("Minimum distance to cover all cities: %d\n", tsp(graph, v));
    return 0;
}
