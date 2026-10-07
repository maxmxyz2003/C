#include <stdio.h>
#include <limits.h>

#define V 4 // Número de vértices en el grafo

void floydWarshall(int graph[V][V]) {
    int dist[V][V];

    // Inicializar la matriz de distancias con las distancias iniciales del grafo
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            dist[i][j] = graph[i][j];

    // Considerar todos los vértices como vértices intermedios y actualizar
    // la matriz de distancias si se encuentra un camino más corto
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX &&
                    dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Imprimir la matriz de distancias mínimas
    printf("Matriz de distancias mínimas:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INT_MAX) {
                printf("INF\t");
            } else {
                printf("%d\t", dist[i][j]);
            }
        }
        printf("\n");
    }
}
int main() {
    // Representación del grafo en forma de matriz de adyacencia
    int graph[V][V] = {{0, 5, INT_MAX, 10},
                       {INT_MAX, 0, 3, INT_MAX},
                       {INT_MAX, INT_MAX, 0, 1},
                       {INT_MAX, INT_MAX, INT_MAX, 0}};
    // Llamar a la función floydWarshall para encontrar las distancias mínimas
    floydWarshall(graph);

    return 0;
}
