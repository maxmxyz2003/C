#include <stdio.h>
#include <stdlib.h>

// Estructura para representar un nodo en el grafo
struct Node {
    int data;
    struct Node* next;
};

// Estructura para representar el grafo
struct Graph {
    int V;
    struct Node** adjList;
};

// Función para crear un nuevo nodo
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Función para crear un grafo con "V" vértices
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->adjList = (struct Node**)malloc(V * sizeof(struct Node*));

    for (int i = 0; i < V; i++)
        graph->adjList[i] = NULL;

    return graph;
}

// Función para agregar una arista dirigida de "src" a "dest" al grafo
void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;
}

// Función recursiva para realizar el ordenamiento topológico
void topologicalSortUtil(struct Graph* graph, int v, int visited[], struct Node** stack) {
    visited[v] = 1;

    struct Node* temp = graph->adjList[v];

    while (temp != NULL) {
        if (!visited[temp->data])
            topologicalSortUtil(graph, temp->data, visited, stack);

        temp = temp->next;
    }

    // Apila el vértice actual
    struct Node* newNode = createNode(v);
    newNode->next = *stack;
    *stack = newNode;
}

// Función principal para realizar el ordenamiento topológico
void topologicalSort(struct Graph* graph) {
    int* visited = (int*)malloc(graph->V * sizeof(int));
    for (int i = 0; i < graph->V; i++)
        visited[i] = 0;

    struct Node* stack = NULL;

    // Llama a la función utilitaria para cada vértice no visitado
    for (int i = 0; i < graph->V; i++) {
        if (!visited[i])
            topologicalSortUtil(graph, i, visited, &stack);
    }

    // Imprime el orden topológico
    printf("Orden topologico:\n");
    while (stack != NULL) {
        printf("%d ", stack->data);
        stack = stack->next;
    }
}

int main() {
    int V = 6;
    struct Graph* graph = createGraph(V);
    addEdge(graph, 5, 2);
    addEdge(graph, 5, 0);
    addEdge(graph, 4, 0);
    addEdge(graph, 4, 1);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 1);
    topologicalSort(graph);
    return 0;
}
