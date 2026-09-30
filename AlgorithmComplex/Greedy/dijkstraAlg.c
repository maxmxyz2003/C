#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#define V 9 // Número de nodos en el grafo
int encontrarNodoMenorDistancia(int distancias[], bool conjuntoSPT[])
{
    int min = INT_MAX, min_indice;
    for (int v = 0; v < V; v++)
    {
        if (!conjuntoSPT[v] && distancias[v] <= min)
        {
            min = distancias[v];
            min_indice = v;
        }
    }
    return min_indice;
}
void imprimirSolucion(int distancias[], int n)
{
    printf("Nodo \t Distancia desde el Nodo de Origen\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, distancias[i]);
}
void dijkstra(int grafo[V][V], int nodoOrigen)
{
    int distancias[V];   // Almacena la distancia más corta desde el nodo de origen
    bool conjuntoSPT[V]; // Conjunto de nodos incluidos en el árbol de caminos más cortos
    // Inicializar todas las distancias como infinito y el conjuntoSPT como falso
    for (int i = 0; i < V; i++)
    {
        distancias[i] = INT_MAX;
        conjuntoSPT[i] = false;
    }
    // La distancia al nodo de origen siempre es cero
    distancias[nodoOrigen] = 0;
    // Encontrar el camino más corto para todos los nodos
    for (int count = 0; count < V - 1; count++)
    {
        // Elegir el nodo de menor distancia no incluido aún en el conjuntoSPT
        int u = encontrarNodoMenorDistancia(distancias, conjuntoSPT);
        // Marcar el nodo elegido como incluido en el conjuntoSPT
        conjuntoSPT[u] = true;
        // Actualizar la distancia de los nodos adyacentes al nodo elegido
        for (int v = 0; v < V; v++)
        {
            if (!conjuntoSPT[v] && grafo[u][v] && distancias[u] != INT_MAX &&
                distancias[u] + grafo[u][v] < distancias[v])
            {
                distancias[v] = distancias[u] + grafo[u][v];
            }
        }
    }
    // Imprimir la solución
    imprimirSolucion(distancias, V);
}
int main(){
    int grafo[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                       {4, 0, 8, 0, 0, 0, 0, 11, 0},
                       {0, 8, 0, 7, 0, 4, 0, 0, 2},
                       {0, 0, 7, 0, 9, 14, 0, 0, 0},
                       {0, 0, 0, 9, 0, 10, 0, 0, 0},
                       {0, 0, 4, 14, 10, 0, 2, 0, 0},
                       {0, 0, 0, 0, 0, 2, 0, 1, 6},
                       {8, 11, 0, 0, 0, 0, 1, 0, 7},
                       {0, 0, 2, 0, 0, 0, 6, 7, 0}
                      };
    dijkstra(grafo, 0);
    return 0;
}
