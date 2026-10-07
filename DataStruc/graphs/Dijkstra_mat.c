#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#define MAX_VERTICES 100
typedef struct {
    int vertex;
    int distance;
} Node;
void dijkstra(int graph[MAX_VERTICES][MAX_VERTICES], int numVertices, int source, int distances[]) {
    bool visited[MAX_VERTICES]={false};
    for (int i = 0; i < numVertices; ++i)
        distances[i] = INT_MAX;
    distances[source] = 0;
    for (int count = 0; count < numVertices - 1; ++count) {
        int minDistance = INT_MAX;
        int minVertex;
        // Find the vertex with the minimum distance
        for (int v = 0; v < numVertices; ++v) {
            if (!visited[v] && distances[v] < minDistance) {
                minDistance = distances[v];
                minVertex = v;
            }
        }
        visited[minVertex] = true;
        // Update distances of adjacent vertices
        for (int v = 0; v < numVertices; ++v) {
            if (!visited[v] && graph[minVertex][v] && distances[minVertex] != INT_MAX && distances[minVertex] + graph[minVertex][v] < distances[v]) {
                distances[v] = distances[minVertex] + graph[minVertex][v];
            }
        }
    }
}
int main() {
    int numVertices, source;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &numVertices);

    int graph[MAX_VERTICES][MAX_VERTICES];
    printf("Enter the adjacency matrix for the graph:\n");
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            scanf("%d", &graph[i][j]);
        }
    }
    printf("Enter the source vertex for Dijkstra's algorithm: ");
    scanf("%d", &source);

    int distances[MAX_VERTICES];
    dijkstra(graph, numVertices, source, distances);

    printf("Shortest distances from source vertex %d:\n", source);
    for (int i = 0; i < numVertices; ++i) {
        printf("Vertex %d: %d\n", i, distances[i]);
    }
    return 0;
}
