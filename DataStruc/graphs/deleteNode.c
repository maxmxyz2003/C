#include <stdio.h>
#define MAX_VERTICES 100
void deleteVertex(int matrix[MAX_VERTICES][MAX_VERTICES], int* numVertices, int vertexToDelete) {
    if (vertexToDelete < 0 || vertexToDelete >= *numVertices) {
        printf("Invalid vertex to delete.\n");
        return;
    }
    // Shift rows up
    for (int i = vertexToDelete; i < *numVertices - 1; i++) {
        for (int j = 0; j < *numVertices; j++) {
            matrix[i][j] = matrix[i + 1][j];
        }
    }
    // Shift columns left
    for (int i = vertexToDelete; i < *numVertices - 1; i++) {
        for (int j = 0; j < *numVertices - 1; j++) {
            matrix[j][i] = matrix[j][i + 1];
        }
    }
    (*numVertices)--;
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
    printf("Original Adjacency Matrix:\n");
    printMatrix(adjacencyMatrix, numVertices);
    int vertexToDelete = 2;  // Change this to the vertex you want to delete
    deleteVertex(adjacencyMatrix, &numVertices, vertexToDelete);
    printf("\nAdjacency Matrix after deleting vertex %d:\n", vertexToDelete);
    printMatrix(adjacencyMatrix, numVertices);
    return 0;
}
