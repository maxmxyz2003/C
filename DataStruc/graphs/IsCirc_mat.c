#include <stdio.h>
#define MAX_VERTICES 100
int visited[MAX_VERTICES];
int parent[MAX_VERTICES];
int hasCircuit(int matrix[MAX_VERTICES][MAX_VERTICES], int numVertices, int vertex, int prevVertex) {
    visited[vertex] = 1;
    for (int i = 0; i < numVertices; i++) {
        if (matrix[vertex][i]) {
            if (!visited[i]) {
                parent[i] = vertex;
                if (hasCircuit(matrix, numVertices, i, vertex)) {
                    return 1;
                }
            } else if (i != prevVertex && parent[vertex] != i) {
                return 1;
            }
        }
    }
    return 0;
}
void resetVisited(int numVertices) {
    for (int i = 0; i < numVertices; i++) {
        visited[i] = 0;
        parent[i] = -1;
    }
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
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}
    };
    printf("Adjacency Matrix:\n");
    printMatrix(adjacencyMatrix, numVertices);
    int hasCycle = 0;
    for (int i = 0; i < numVertices; i++) {
        resetVisited(numVertices);
        if (!visited[i]) {
            if (hasCircuit(adjacencyMatrix, numVertices, i, -1)) {
                hasCycle = 1;
                break;
            }
        }
    }
    if (hasCycle) {
        printf("\nThe graph contains a cycle.\n");
    } else {
        printf("\nThe graph does not contain a cycle.\n");
    }
    return 0;
}
