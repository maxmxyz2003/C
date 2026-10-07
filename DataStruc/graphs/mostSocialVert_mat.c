#include <stdio.h>
#define MAX_VERTICES 100
int findMostSociableVertex(int matrix[MAX_VERTICES][MAX_VERTICES], int numVertices) {
    int mostSociableVertex = 0;
    int highestDegree = 0;
    for (int i = 0; i < numVertices; i++) {
        int degree = 0;
        for (int j = 0; j < numVertices; j++) {
            if (matrix[i][j] == 1) {
                degree++;
            }
        }
        if (degree > highestDegree) {
            highestDegree = degree;
            mostSociableVertex = i;
        }
    }
    return mostSociableVertex;
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

    int mostSociable = findMostSociableVertex(adjacencyMatrix, numVertices);

    printf("\nThe most sociable vertex is: %d\n", mostSociable);

    return 0;
}
