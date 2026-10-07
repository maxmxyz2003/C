#include <stdio.h>
#include <stdlib.h>

// Estructura para representar una arista
typedef struct {
  int origen, destino, peso;
} Arista;

// Estructura para representar un conjunto disjunto
typedef struct {
  int *padre, *rango;
  int numNodos;
} ConjuntoDisjunto;

// Función para inicializar un conjunto disjunto
void inicializarConjuntoDisjunto(ConjuntoDisjunto *conjunto, int numNodos) {
  conjunto->numNodos = numNodos;
  conjunto->padre = (int *)malloc(numNodos * sizeof(int));
  conjunto->rango = (int *)malloc(numNodos * sizeof(int));
  // Inicializar cada nodo como un conjunto independiente
  for (int i = 0; i < numNodos; i++) {
    conjunto->padre[i] = i;
    conjunto->rango[i] = 0;
  }
}
// Función para encontrar el representante (raíz) de un conjunto
int encontrarRepresentante(ConjuntoDisjunto *conjunto, int nodo) {
  if (conjunto->padre[nodo] != nodo) {
    // Comprimir la ruta (Path Compression)
    conjunto->padre[nodo] =
        encontrarRepresentante(conjunto, conjunto->padre[nodo]);
  }
  return conjunto->padre[nodo];
}
// Función para unir dos conjuntos disjuntos por sus representantes
void unirConjuntos(ConjuntoDisjunto *conjunto, int x, int y) {
  int representanteX = encontrarRepresentante(conjunto, x);
  int representanteY = encontrarRepresentante(conjunto, y);
  // Unir por rango (Union by Rank)
  if (conjunto->rango[representanteX] < conjunto->rango[representanteY]) {
    conjunto->padre[representanteX] = representanteY;
  } else if (conjunto->rango[representanteX] >
             conjunto->rango[representanteY]) {
    conjunto->padre[representanteY] = representanteX;
  } else {
    // Si los rangos son iguales, elige uno como el representante y aumenta el
    // rango
    conjunto->padre[representanteX] = representanteY;
    conjunto->rango[representanteY]++;
  }
}
// Función de comparación para ordenar las aristas por peso
int compararAristas(const void *a, const void *b) {
  return ((Arista *)a)->peso - ((Arista *)b)->peso;
}
// Función principal del algoritmo de Kruskal
void kruskal(Arista *aristas, int numAristas, int numNodos) {
  // Ordenar las aristas por peso de manera ascendente
  qsort(aristas, numAristas, sizeof(Arista), compararAristas);
  // Inicializar un conjunto disjunto
  ConjuntoDisjunto conjunto;
  inicializarConjuntoDisjunto(&conjunto, numNodos);
  printf("Árbol de Expansión Mínima (Kruskal):\n");
  // Procesar cada arista en orden ascendente de peso
  for (int i = 0; i < numAristas; i++) {
    int representanteOrigen =
        encontrarRepresentante(&conjunto, aristas[i].origen);
    int representanteDestino =
        encontrarRepresentante(&conjunto, aristas[i].destino);
    // Verificar si la arista forma un ciclo en el árbol actual
    if (representanteOrigen != representanteDestino) {
      printf("(%d, %d) - Peso: %d\n", aristas[i].origen, aristas[i].destino,
             aristas[i].peso);
      // Unir los conjuntos disjuntos
      unirConjuntos(&conjunto, representanteOrigen, representanteDestino);
    }
  }
  // Liberar memoria utilizada por el conjunto disjunto
  free(conjunto.padre);
  free(conjunto.rango);
}

int main() {
  // Ejemplo: Grafo ponderado no dirigido con 4 nodos y 5 aristas
  int numNodos = 4;
  int numAristas = 5;
  Arista aristas[] = {
      {0, 1, 2}, {0, 2, 4}, {1, 2, 1}, {1, 3, 3}, {2, 3, 5},
  };
  // Aplicar el algoritmo de Kruskal
  kruskal(aristas, numAristas, numNodos);
  return 0;
}
