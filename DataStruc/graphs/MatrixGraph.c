#include <stdio.h>
#include <stdbool.h>
#define MAX_NODOS 100
typedef struct {
    int matriz[MAX_NODOS][MAX_NODOS];
    int numNodos;
} GrafoMatriz;
void inicializarGrafoMatriz(GrafoMatriz* grafo){
    grafo->numNodos = 0;
    for (int i = 0; i < MAX_NODOS; i++) {
        for (int j = 0; j < MAX_NODOS; j++) {
            grafo->matriz[i][j] = 0;
        }
    }
}
void agregarNodoMatriz(GrafoMatriz* grafo) {
    if (grafo->numNodos < MAX_NODOS) {
        grafo->numNodos++;
    } else {
        printf("El número máximo de nodos ha sido alcanzado.\n");
    }
}
void agregarAristaMatriz(GrafoMatriz* grafo, int origen, int destino, int peso) {
    if (origen >= 0 && origen < grafo->numNodos && destino >= 0 && destino < grafo->numNodos) {
        grafo->matriz[origen][destino] = peso;
        // Si el grafo es no dirigido, descomenta la siguiente línea:
        // grafo->matriz[destino][origen] = peso;
    } else {
        printf("Nodos fuera de rango.\n");
    }
}

void eliminarNodoMatriz(GrafoMatriz* grafo, int nodo) {
    if (nodo >= 0 && nodo < grafo->numNodos) {
        for (int i = 0; i < grafo->numNodos; i++) {
            grafo->matriz[i][nodo] = 0;
            grafo->matriz[nodo][i] = 0;
        }
        grafo->numNodos--;
    } else {
        printf("Nodo fuera de rango.\n");
    }
}
void imprimirMatriz(GrafoMatriz* grafo) {
    for (int i = 0; i < grafo->numNodos; i++) {
        for (int j = 0; j < grafo->numNodos; j++) {
            printf("%d\t", grafo->matriz[i][j]);
        }
        printf("\n");
    }
}
int main() {
    GrafoMatriz grafo;
    inicializarGrafoMatriz(&grafo);
    agregarNodoMatriz(&grafo);
    agregarNodoMatriz(&grafo);
    agregarNodoMatriz(&grafo);
    agregarAristaMatriz(&grafo, 0, 1, 3);
    agregarAristaMatriz(&grafo, 1, 0, 3);
    agregarAristaMatriz(&grafo, 0, 2, 5);
    agregarAristaMatriz(&grafo, 2, 0, 5);
    agregarAristaMatriz(&grafo, 1, 2, 4);
    agregarAristaMatriz(&grafo, 2, 1, 4);
    printf("Matriz de Adyacencia:\n");
    imprimirMatriz(&grafo);
    // eliminarNodoMatriz(&grafo, 0);
    // printf("\nMatriz de Adyacencia despues de eliminar el nodo 0:\n");
    // imprimirMatriz(&grafo);
    return 0;
}
