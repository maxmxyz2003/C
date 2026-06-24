#include <stdio.h>
#include <stdlib.h>
typedef struct Nodo {
  int destino;
  int peso;
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
  grafo->array =(ListaAdyacencia *)malloc(numNodos * sizeof(ListaAdyacencia));
  for (int i = 0; i < numNodos; i++) {
    grafo->array[i].cabeza = NULL;
  }
}
void agregarNodoLista(GrafoLista *grafo) {
  grafo->numNodos++;
  grafo->array =realloc(grafo->array, grafo->numNodos * sizeof(ListaAdyacencia));
  grafo->array[grafo->numNodos - 1].cabeza = NULL;
}

void agregarAristaLista(GrafoLista *grafo, int origen, int destino, int peso) {
  if (origen >= 0 && origen < grafo->numNodos && destino >= 0 &&destino < grafo->numNodos) {
    Nodo *nuevoNodo = (Nodo *)malloc(sizeof(Nodo));
    nuevoNodo->destino = destino;
    nuevoNodo->peso = peso;
    nuevoNodo->siguiente = grafo->array[origen].cabeza;
    grafo->array[origen].cabeza = nuevoNodo;
  } else {
    printf("Nodos fuera de rango.\n");
  }
}
void eliminarNodoLista(GrafoLista *grafo, int nodo) {
  if (nodo >= 0 && nodo < grafo->numNodos) {
    for (int i = 0; i < grafo->numNodos; i++) {
      Nodo *actual = grafo->array[i].cabeza;
      Nodo *previo = NULL;
      while (actual) {
        if (actual->destino == nodo) {
          if (previo == NULL) {
            grafo->array[i].cabeza = actual->siguiente;
          } else {
            previo->siguiente = actual->siguiente;
          }
          free(actual);
          break;
        }
        previo = actual;
        actual = actual->siguiente;
      }
    }
    // Eliminar la lista de adyacencia del nodo
    free(grafo->array[nodo].cabeza);
    grafo->array[nodo].cabeza = NULL;
    // Reducir el número de nodos
    grafo->numNodos--;
    grafo->array =realloc(grafo->array, grafo->numNodos * sizeof(ListaAdyacencia));
  } else {
    printf("Nodo fuera de rango.\n");
  }
}
void imprimirLista(GrafoLista *grafo) {
  for (int i = 0; i < grafo->numNodos; i++) {
    Nodo *actual = grafo->array[i].cabeza;
    printf("Lista de Adyacencia del Nodo %d: ", i);
    while (actual != NULL) {
      printf("(%d, %d) -> ", actual->destino, actual->peso);
      actual = actual->siguiente;
    }
    printf("NULL\n");
  }
}

int main() {
  GrafoLista grafo;
  inicializarGrafoLista(&grafo, 2);
  agregarAristaLista(&grafo, 0, 1, 3);
  agregarAristaLista(&grafo, 1, 0, 2);
  printf("Lista de Adyacencia:\n");
  imprimirLista(&grafo);
  eliminarNodoLista(&grafo, 0);
  printf("\nLista de Adyacencia después de eliminar el nodo 0:\n");
  imprimirLista(&grafo);
  return 0;
}
