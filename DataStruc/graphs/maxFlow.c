#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#define V 6 // Número de nodos en el grafo
// Función para encontrar el camino de aumento en el grafo residual
bool dfs(int rGraph[V][V], int s, int t, int parent[]) {
    // Array para marcar los nodos visitados
    bool visited[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
    // Pila para realizar la búsqueda en profundidad
    int stack[V];
    int top = -1;
    stack[++top] = s;
    visited[s] = true;
    parent[s] = -1;
    while (top >= 0) {
        int u = stack[top--];
        for (int v = 0; v < V; v++) {
            if (!visited[v] && rGraph[u][v] > 0) {
                stack[++top] = v;
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    // Devuelve true si se encontró un camino de aumento desde la fuente hasta el sumidero
    return visited[t];
}
// Función para calcular el flujo máximo en el grafo dado
int fordFulkerson(int graph[V][V], int s, int t) {
    int rGraph[V][V]; // Grafo residual
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
             rGraph[i][j] = graph[i][j];
    int parent[V]; // Array para almacenar el camino de aumento
    int maxFlow = 0; // Inicializar el flujo máximo
    // Mientras haya un camino de aumento en el grafo residual
    while (dfs(rGraph, s, t, parent)) {
        int pathFlow = INT_MAX;
        // Encuentra la capacidad mínima a lo largo del camino de aumento
        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            pathFlow = (rGraph[u][v] < pathFlow) ? rGraph[u][v] : pathFlow;
        }
        // Actualiza las capacidades residuales del grafo y del grafo residual
        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            rGraph[u][v] -= pathFlow;
            rGraph[v][u] += pathFlow;
        }
        // Agrega el flujo del camino de aumento al flujo máximo
        maxFlow += pathFlow;
    }
    return maxFlow;
}
int main() {
    // Grafo con capacidades de las aristas
    int graph[V][V] = {{0, 16, 13, 0, 0, 0},
                       {0, 0, 10, 12, 0, 0},
                       {0, 4, 0, 0, 14, 0},
                       {0, 0, 9, 0, 0, 20},
                       {0, 0, 0, 7, 0, 4},
                       {0, 0, 0, 0, 0, 0}};
    int source = 0;    // Fuente
    int sink = 5;      // Sumidero
    int maxFlow = fordFulkerson(graph, source, sink);
    printf("El flujo máximo del grafo es: %d\n", maxFlow);
    return 0;
}
