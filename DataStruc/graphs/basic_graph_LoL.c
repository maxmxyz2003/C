#include <stdio.h>
#include <stdlib.h>
// Structure for a node in the graph
typedef struct Node {
    int data;
    struct Node* next;
} Node;
// Structure for the graph
typedef struct Graph {
    int vertices;
    Node** adjLists;
} Graph;
// Function to create a new graph with 'V' vertices
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->vertices = vertices;
    graph->adjLists = (Node**)malloc(vertices * sizeof(Node*));
    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
    }return graph;
}
// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    // Create a new node for the destination vertex
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = dest;
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
}
// Function to print the graph
void printGraph(Graph* graph) {
    for (int i = 0; i < graph->vertices; i++) {
        Node* currentNode = graph->adjLists[i];
        printf("Adjacency list of vertex %d:\n", i+1);
        while (currentNode) {
            printf(" -> %d", currentNode->data+1);
            currentNode = currentNode->next;
        }
        printf("\n");
    }
}
int main() {
    int V = 5;
    Graph* graph = createGraph(V);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 0, 3);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    printGraph(graph);
    return 0;
}
