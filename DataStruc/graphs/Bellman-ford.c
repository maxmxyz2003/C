#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX_NODOS 100
#define MAX_ARISTAS 100

typedef struct {
    int origen, destino, peso;
} Arista;

typedef struct {
    int distancia[MAX_NODOS];
    int numNodos, numAristas;
    Arista aristas[MAX_ARISTAS];
} Grafo;

void inicializarGrafo(Grafo* grafo, int numNodos, int numAristas) {
    grafo->numNodos = numNodos;
    grafo->numAristas = numAristas;
    for (int i = 0; i < numNodos; i++) {
        grafo->distancia[i] = INT_MAX;
    }
}

void agregarArista(Grafo* grafo, int origen, int destino, int peso) {
    if (grafo->numAristas < MAX_ARISTAS) {
        grafo->aristas[grafo->numAristas].origen = origen;
        grafo->aristas[grafo->numAristas].destino = destino;
        grafo->aristas[grafo->numAristas].peso = peso;
        grafo->numAristas++;
    } else {
        printf("Número máximo de aristas alcanzado.\n");
    }
}

void bellmanFord(Grafo* grafo, int origen) {
    grafo->distancia[origen] = 0;
    // Relajación de aristas repetidas V-1 veces
    for (int i = 0; i < grafo->numNodos - 1; i++) {
        for (int j = 0; j < grafo->numAristas; j++) {
            int u = grafo->aristas[j].origen;
            int v = grafo->aristas[j].destino;
            int peso = grafo->aristas[j].peso;
            if (grafo->distancia[u] != INT_MAX && grafo->distancia[u] + peso < grafo->distancia[v]) {
                grafo->distancia[v] = grafo->distancia[u] + peso;
            }
        }
    }
    // Verificar ciclos de peso negativo
    for (int i = 0; i < grafo->numAristas; i++) {
        int u = grafo->aristas[i].origen;
        int v = grafo->aristas[i].destino;
        int peso = grafo->aristas[i].peso;

        if (grafo->distancia[u] != INT_MAX && grafo->distancia[u] + peso < grafo->distancia[v]) {
            printf("El grafo contiene ciclos de peso negativo.\n");
            return;
        }
    }
}

void imprimirDistancias(Grafo* grafo, int origen) {
    printf("Distancias más cortas desde el nodo %d:\n", origen);
    for (int i = 0; i < grafo->numNodos; i++) {
        printf("Nodo %d -> Nodo %d: %d\n", origen, i, grafo->distancia[i]);
    }
}
int main() {
    Grafo grafo;
    int numNodos = 5;
    int numAristas = 8;
    inicializarGrafo(&grafo, numNodos, numAristas);
    agregarArista(&grafo, 0, 1, -1);
    agregarArista(&grafo, 0, 2, 4);
    agregarArista(&grafo, 1, 2, 3);
    agregarArista(&grafo, 1, 3, 2);
    agregarArista(&grafo, 1, 4, 2);
    agregarArista(&grafo, 3, 2, 5);
    agregarArista(&grafo, 3, 1, 1);
    agregarArista(&grafo, 4, 3, -3);
    int origen = 0;
    bellmanFord(&grafo, origen);
    imprimirDistancias(&grafo, origen);
    return 0;
}
