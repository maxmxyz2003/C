#include <stdio.h>
#include <stdbool.h>
#define MAX_NODOS 100
typedef struct {
    int matriz[MAX_NODOS][MAX_NODOS];
    int numNodos;
} GrafoMatriz;
void inicializarGrafoMatriz(GrafoMatriz* grafo, int numNodos) {
    grafo->numNodos = numNodos;
    for (int i = 0; i < MAX_NODOS; i++) {
        for (int j = 0; j < MAX_NODOS; j++) {
            grafo->matriz[i][j] = 0;
        }
    }
}
void agregarAristaMatriz(GrafoMatriz* grafo, int origen, int destino) {
    if (origen >= 0 && origen < grafo->numNodos && destino >= 0 && destino < grafo->numNodos) {
        grafo->matriz[origen][destino] = 1;
        // Si el grafo es no dirigido, descomenta la siguiente línea:
        // grafo->matriz[destino][origen] = 1;
    } else {
        printf("Nodos fuera de rango.\n");
    }
}

void DFSRecursivo(GrafoMatriz* grafo, int nodo, bool visitados[]) {
    printf("%d ", nodo);
    visitados[nodo] = true;
    for (int i = 0; i < grafo->numNodos; i++) {
        if (grafo->matriz[nodo][i] && !visitados[i]) {
            DFSRecursivo(grafo, i, visitados);
        }
    }
}
void DFS(GrafoMatriz* grafo, int inicio) {
    bool visitados[MAX_NODOS];
    for (int i = 0; i < grafo->numNodos; i++) {
        visitados[i] = false;
    }
    printf("Recorrido en Profundidad (DFS) desde el nodo %d: ", inicio);
    DFSRecursivo(grafo, inicio, visitados);
    printf("\n");
}  
int main() {
    GrafoMatriz grafo;
    inicializarGrafoMatriz(&grafo, 5);
    agregarAristaMatriz(&grafo, 0, 1);
    agregarAristaMatriz(&grafo, 0, 2);
    agregarAristaMatriz(&grafo, 1, 3);
    agregarAristaMatriz(&grafo, 2, 4);
    DFS(&grafo, 0);
    return 0;
}
