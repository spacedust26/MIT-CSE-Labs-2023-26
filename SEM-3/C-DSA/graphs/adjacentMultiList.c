#include <stdio.h>
#include <stdlib.h>

// Define the structure for representing edges in a graph
typedef struct edge *edge_pointer;
typedef struct edge {
    short int marked;
    int vertex1, vertex2;
    edge_pointer path1, path2;
} Edge;

// Function to create a new edge
edge_pointer createEdge(int v1, int v2) {
    edge_pointer newEdge = (edge_pointer)malloc(sizeof(Edge));
    if (newEdge == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    newEdge->marked = 0; // Marked as unmarked initially
    newEdge->vertex1 = v1;
    newEdge->vertex2 = v2;
    newEdge->path1 = NULL;
    newEdge->path2 = NULL;

    return newEdge;
}

// Function to print information about an edge
void printEdge(edge_pointer edge) {
    printf("Edge (%d, %d) Marked: %d\n", edge->vertex1, edge->vertex2, edge->marked);
}

// Function to free memory allocated for edges
void freeEdges(edge_pointer edge) {
    if (edge != NULL) {
        freeEdges(edge->path1);
        freeEdges(edge->path2);
        free(edge);
    }
}

int main() {
    int v1, v2;

    // Get user input to create edges
    printf("Enter the vertices for the first edge (vertex1 vertex2): ");
    scanf("%d %d", &v1, &v2);
    edge_pointer edge1 = createEdge(v1, v2);

    printf("Enter the vertices for the second edge (vertex1 vertex2): ");
    scanf("%d %d", &v1, &v2);
    edge_pointer edge2 = createEdge(v1, v2);

    printf("Enter the vertices for the third edge (vertex1 vertex2): ");
    scanf("%d %d", &v1, &v2);
    edge_pointer edge3 = createEdge(v1, v2);

    // Connect edges to form paths
    edge1->path1 = edge2;
    edge2->path1 = edge3;
    edge3->path1 = edge1;

    // Print information about edges
    printEdge(edge1);
    printEdge(edge2);
    printEdge(edge3);

    // Free memory allocated for edges
    freeEdges(edge1);

    return 0;
}
