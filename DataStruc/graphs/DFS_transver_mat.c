#include <stdio.h>
#include <stdbool.h>
#define MAX_VERTICES 100
void dfs(int vertex, bool visited[], int graph[][MAX_VERTICES], int numVertices) {
    visited[vertex] = true;
    printf("%d ", vertex);
    for (int neighbor = 0; neighbor < numVertices; ++neighbor) {
        if (graph[vertex][neighbor] ==1&& !visited[neighbor]) {
            dfs(neighbor, visited, graph, numVertices);
        }
    }
}
void dfsTraversal(int graph[][MAX_VERTICES], int numVertices, int startVertex) {
    bool visited[MAX_VERTICES] = { false };
    dfs(startVertex, visited, graph, numVertices);
}
int main() {
    int numVertices, startVertex;
    int matrix[100][100]={{0,1,1},{1,0,0},{1,0,0}
    };
    dfsTraversal(matrix, 3, 0);
    //printf("Enter the number of vertices in the graph: ");
    scanf("%d", &numVertices);
    int graph[MAX_VERTICES][MAX_VERTICES];
    //printf("Enter the adjacency matrix for the graph:\n");
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            scanf("%d", &graph[i][j]);
        }
    }
    //printf("Enter the start vertex for DFS traversal: ");
    scanf("%d", &startVertex);
    //printf("DFS traversal starting from vertex %d: ", startVertex);
    dfsTraversal(graph, numVertices, startVertex);
    printf("\n");
    return 0;
}
