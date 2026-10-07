#include <stdio.h>
#include <limits.h>

#define V 5 // Número de vértices en el grafo

int minKey(int key[], int mstSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (mstSet[v] == 0 && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }

    return min_index;
}

void printMST(int parent[], int graph[V][V]) {
    printf("Arista   Peso\n");
    for (int i = 1; i < V; i++)
        printf("%d - %d    %d \n", parent[i], i, graph[i][parent[i]]);
}

void primMST(int graph[V][V]) {
    int parent[V]; // Array para almacenar el árbol de expansión mínima final
    int key[V];    // Claves utilizadas para seleccionar el vértice con el peso mínimo
    int mstSet[V]; // Conjunto para representar los vértices ya incluidos en el árbol de expansión mínima

    // Inicializar todas las claves como infinito y mstSet como falso
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    // Siempre incluir el primer vértice en el árbol de expansión mínima.
    // Hacer la clave 0 para que este vértice sea recogido primero.
    key[0] = 0;
    parent[0] = -1; // El primer nodo no tiene un nodo padre

    // Árbol de expansión mínima tiene V-1 aristas
    for (int count = 0; count < V - 1; count++) {
        // Seleccionar el vértice con la clave mínima del conjunto de vértices aún no procesados
        int u = minKey(key, mstSet);

        // Incluir el vértice seleccionado en el conjunto de vértices procesados
        mstSet[u] = 1;

        // Actualizar el valor de clave y el índice de los vértices adyacentes del vértice seleccionado
        for (int v = 0; v < V; v++) {
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Imprimir el árbol de expansión mínima construido
    printMST(parent, graph);
}

int main() {
    // Representación del grafo en forma de matriz de adyacencia
    int graph[V][V] = {{0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };
    // Llamar a la función primMST para encontrar el árbol de expansión mínima
    primMST(graph);
    return 0;
}
/*
(por ejemplo, Ford-Fulkerson):
*/
