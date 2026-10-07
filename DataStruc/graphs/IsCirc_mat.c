#include <stdbool.h>
#define MAX_VERTICES 100
bool isCircuit(int graph[MAX_VERTICES][MAX_VERTICES], int vertex, bool visited[], int parent) {
    visited[vertex] = true;
    for (int i = 0; i < MAX_VERTICES; i++) {
        if (graph[vertex][i] == 1) {
            if (!visited[i]) {
                if (isCircuit(graph, i, visited, vertex))
                    return true;
            } else if (i != parent) {
                return true;
            }
        }
    }
    return false;
}
bool isCircuit(int graph[MAX_VERTICES][MAX_VERTICES], int numVertices) {
    // Check if the graph has at least 3 vertices
    if (numVertices < 3) {
        return false;
    }
    // Check if every vertex has degree 2
    for (int i = 0; i < numVertices; i++) {
        int degree = 0;
        for (int j = 0; j < numVertices; j++) {
            if (graph[i][j] == 1) {
                degree++;
            }
        }
        if (degree != 2) {
            return false;
        }
    }
    // Check if the graph is connected
    int visited[MAX_VERTICES] = {0};
    int queue[MAX_VERTICES];
    int front = 0, rear = 0;

    visited[0] = 1;
    queue[rear++] = 0;

    while (front < rear) {
        int currentVertex = queue[front++];
        for (int i = 0; i < numVertices; i++) {
            if (graph[currentVertex][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }

    for (int i = 0; i < numVertices; i++) {
        if (visited[i] == 0) {
            return false;
        }
    }

    return true;
}
bool hasCircuit(int graph[MAX_VERTICES][MAX_VERTICES], int numVertices) {
    bool visited[MAX_VERTICES] = { false };

    for (int i = 0; i < numVertices; i++) {
        if (!visited[i] && isCircuit(graph, i, visited, -1))
            return true;
    }

    return false;
}
int main() {
    int numVertices;
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);
    int graph[MAX_VERTICES][MAX_VERTICES];
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    if (hasCircuit(graph, numVertices)) {
        printf("The graph contains a circuit.\n");
    } else {
        printf("The graph does not contain a circuit.\n");
    }

    return 0;
}
/*

*/
