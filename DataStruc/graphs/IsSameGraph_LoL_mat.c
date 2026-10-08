#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_NODES 100

typedef struct {
    int matrix[MAX_NODES][MAX_NODES];
    int numNodes;
} GraphMatrix;

typedef struct Node {
    int destination;
    int weight;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
} AdjList[MAX_NODES];

typedef struct {
    AdjList array;
    int numNodes;
} GraphList;

bool areEqual(GraphMatrix *graphMatrix, GraphList *graphList) {
    if (graphMatrix->numNodes != graphList->numNodes) {
        return false; // Diferente cantidad de nodos
    }
    for (int i = 0; i < graphMatrix->numNodes; ++i) {
        for (int j = 0; j < graphMatrix->numNodes; ++j) {
            if (graphMatrix->matrix[i][j] != -1) {// Si hay una conexión en la matriz de adyacencia
                Node *current = graphList->array[i].head;
                bool found = false;
                while (current) {
                    if (current->destination == j && current->weight == graphMatrix->matrix[i][j]) {
                        found = true;
                        break;
                    }
                    current = current->next;
                }
                if (!found) {
                    return false; // No se encontró la conexión en la lista de adyacencia
                }
            }
        }
    }
    return true; // Los grafos son iguales
}

// Función de prueba
int main() {
    GraphMatrix graphMatrix = {
        .numNodes = 3,
        .matrix = {
            { -1, 2, -1 },
            { 2, -1, 3 },
            { -1, 3, -1 }
        }
    };

    GraphList graphList = {
        .numNodes = 3,
        .array = {
            { .head = NULL },
            { .head = NULL },
            { .head = NULL }
        }
    };

    // Código para inicializar la lista de adyacencia, agregar nodos y conexiones...

    if (areEqual(&graphMatrix, &graphList)) {
        printf("Los grafos son iguales.\n");
    } else {
        printf("Los grafos son diferentes.\n");
    }

    return 0;
}
