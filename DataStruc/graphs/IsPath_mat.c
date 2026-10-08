#include <stdio.h>
#define MAX_VERTICES 100
int visited[MAX_VERTICES];
int hasPath(int matrix[MAX_VERTICES][MAX_VERTICES], int numVertices, int start, int end) {
    if (start == end)
        return 1; // There's a path from a vertex to itself
    visited[start] = 1;
    for (int i = 0; i < numVertices; i++) {
        if (matrix[start][i] && !visited[i]) {
            if (hasPath(matrix, numVertices, i, end)) {
                return 1; // A path was found
            }
        }
    }
    return 0; // No path was found
}
void resetVisited(int numVertices) {
    for (int i = 0; i < numVertices; i++)
        visited[i] = 0;
}
void printMatrix(int matrix[MAX_VERTICES][MAX_VERTICES], int numVertices) {
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int numVertices = 5;  // Change this to the number of vertices in your graph
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES] = {
        {0, 1, 1, 0, 0},
        {1, 0, 0, 1, 1},
        {1, 0, 0, 0, 1},
        {0, 1, 0, 0, 0},
        {0, 1, 1, 0, 0}
    };
    printf("Adjacency Matrix:\n");
    printMatrix(adjacencyMatrix, numVertices);
    int startVertex = 0;  // Change this to the starting vertex
    int endVertex = 3;    // Change this to the ending vertex
    resetVisited(numVertices);
    if (hasPath(adjacencyMatrix, numVertices, startVertex, endVertex))
        printf("\nThere is a path between vertex %d and vertex %d.\n", startVertex, endVertex);
    else
        printf("\nThere is no path between vertex %d and vertex %d.\n", startVertex, endVertex);
    return 0;
}
