#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_NODOS 100
typedef struct Nodo {
  int destino;
  struct Nodo *siguiente;
} Nodo;
typedef struct {
  Nodo *cabeza;
} ListaAdyacencia;
typedef struct {
  ListaAdyacencia *array;
  int numNodos;
} GrafoLista;
void inicializarGrafoLista(GrafoLista *grafo, int numNodos) {
  grafo->numNodos = numNodos;
  grafo->array = (ListaAdyacencia *)malloc(numNodos * sizeof(ListaAdyacencia));
  for (int i = 0; i < numNodos; i++) {
    grafo->array[i].cabeza = NULL;
  }
}
void agregarAristaLista(GrafoLista *grafo, int origen, int destino) {
  if (origen >= 0 && origen < grafo->numNodos && destino >= 0 &&
      destino < grafo->numNodos) {
    Nodo *nuevoNodo = (Nodo *)malloc(sizeof(Nodo));
    nuevoNodo->destino = destino;
    nuevoNodo->siguiente = grafo->array[origen].cabeza;
    grafo->array[origen].cabeza = nuevoNodo;
  } else {
    printf("Nodos fuera de rango.\n");
  }
}
void BFS(GrafoLista *grafo, int nodoInicial) {
  bool *visitado = (bool *)malloc(grafo->numNodos * sizeof(bool));
  for (int i = 0; i < grafo->numNodos; i++) {
    visitado[i] = false;
  }
  int *cola = (int *)malloc(grafo->numNodos * sizeof(int));
  int frente = 0;
  int fin = 0;
  visitado[nodoInicial] = true;
  cola[fin++] = nodoInicial;
  printf("Recorrido BFS desde el nodo %d: ", nodoInicial);
  while (frente != fin) {
    int nodoActual = cola[frente++];
    printf("%d ", nodoActual);
    Nodo *actual = grafo->array[nodoActual].cabeza;
    while (actual != NULL) {
      if (!visitado[actual->destino]) {
        visitado[actual->destino] = true;
        cola[fin++] = actual->destino;
      }
      actual = actual->siguiente;
    }
  }
  printf("\n");
  free(visitado);
  free(cola);
}

int main() {
  GrafoLista grafo;
  inicializarGrafoLista(&grafo, 6);
  agregarAristaLista(&grafo, 0, 1);
  agregarAristaLista(&grafo, 0, 2);
  agregarAristaLista(&grafo, 1, 3);
  agregarAristaLista(&grafo, 1, 4);
  agregarAristaLista(&grafo, 2, 5);
  BFS(&grafo, 0);
  return 0;
}
