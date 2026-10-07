#include <stdio.h>
#include <stdbool.h>
#define MAX_VERTICES 100
typedef struct {
    int vertices[MAX_VERTICES];
    int front, rear;
} Queue;
void initializeQueue(Queue* queue) {
    queue->front = -1;
    queue->rear = -1;
}
bool isQueueEmpty(Queue* queue) {
    return queue->front == -1;
}
bool isQueueFull(Queue* queue) {
    return (queue->rear + 1) % MAX_VERTICES == queue->front;
}
void enqueue(Queue* queue, int vertex) {
    if (isQueueFull(queue)) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }
    if (isQueueEmpty(queue))
        queue->front = 0;
    queue->rear = (queue->rear + 1) % MAX_VERTICES;
    queue->vertices[queue->rear] = vertex;
}
int dequeue(Queue* queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    int vertex = queue->vertices[queue->front];
    if (queue->front == queue->rear)
        initializeQueue(queue);
    else
        queue->front = (queue->front + 1) % MAX_VERTICES;
    return vertex;
}
void dfs(int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES], int numVertices, int startVertex, bool visited[MAX_VERTICES]) {
    visited[startVertex] = true;
    printf("%d ", startVertex);
    for (int i = 0; i < numVertices; i++) {
        if (adjacencyMatrix[startVertex][i] && !visited[i])
            dfs(adjacencyMatrix, numVertices, i, visited);
    }
}
void bfs(int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES], int numVertices, int startVertex) {
    bool visited[MAX_VERTICES] = { false };
    Queue queue;
    initializeQueue(&queue);
    visited[startVertex] = true;
    printf("%d ", startVertex);
    enqueue(&queue, startVertex);
    while (!isQue#include <stdio.h>
#include <stdbool.h>
#define MAX_VERTICES 100
typedef struct {
    int vertices[MAX_VERTICES];
    int front, rear;
} Queue;
void initializeQueue(Queue* queue) {
    queue->front = -1;
    queue->rear = -1;
}
bool isQueueEmpty(Queue* queue) {
    return queue->front == -1;
}
bool isQueueFull(Queue* queue) {
    return (queue->rear + 1) % MAX_VERTICES == queue->front;
}
void enqueue(Queue* queue, int vertex) {
    if (isQueueFull(queue)) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }
    if (isQueueEmpty(queue))
        queue->front = 0;
    queue->rear = (queue->rear + 1) % MAX_VERTICES;
    queue->vertices[queue->rear] = vertex;
}
int dequeue(Queue* queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    int vertex = queue->vertices[queue->front];
    if (queue->front == queue->rear)
        initializeQueue(queue);
    else
        queue->front = (queue->front + 1) % MAX_VERTICES;
    return vertex;
}
void dfs(int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES], int numVertices, int startVertex, bool visited[MAX_VERTICES]) {
    visited[startVertex] = true;
    printf("%d ", startVertex);
    for (int i = 0; i < numVertices; i++) {
        if (adjacencyMatrix[startVertex][i] && !visited[i])
            dfs(adjacencyMatrix, numVertices, i, visited);
    }
}
void bfs(int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES], int numVertices, int startVertex) {
    bool visited[MAX_VERTICES] = { false };
    Queue queue;
    initializeQueue(&queue);
    visited[startVertex] = true;
    printf("%d ", startVertex);
    enqueue(&queue, startVertex);
    while (!isQueueEmpty(&queue)) {
        int currentVertex = dequeue(&queue);
        for (int i = 0; i < numVertices; i++) {
            if (adjacencyMatrix[currentVertex][i] && !visited[i]) {
                visited[i] = true;
                printf("%d ", i);
                enqueue(&queue, i);
            }
        }
    }
}
int main() {
    int numVertices, startVertex;
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
    //printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    //printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            scanf("%d", &adjacencyMatrix[i][j]);
        }
    }
    //printf("Enter the starting vertex for DFS: ");
    scanf("%d", &startVertex);
    printf("DFS traversal: ");
    bool visitedDFS[MAX_VERTICES] = { false };
    dfs(adjacencyMatrix, numVertices, startVertex, visitedDFS);
    printf("\n");
    printf("Enter the starting vertex for BFS: ");
    scanf("%d", &startVertex);
    printf("BFS traversal: ");
    bfs(adjacencyMatrix, numVertices, startVertex);
    printf("\n");
    return 0;
}ueEmpty(&queue)) {
        int currentVertex = dequeue(&queue);
        for (int i = 0; i < numVertices; i++) {
            if (adjacencyMatrix[currentVertex][i] && !visited[i]) {
                visited[i] = true;
                printf("%d ", i);
                enqueue(&queue, i);
            }
        }
    }
}
int main() {
    int numVertices, startVertex;
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
    //printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    //printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            scanf("%d", &adjacencyMatrix[i][j]);
        }
    }
    //printf("Enter the starting vertex for DFS: ");
    scanf("%d", &startVertex);
    printf("DFS traversal: ");
    bool visitedDFS[MAX_VERTICES] = { false };
    dfs(adjacencyMatrix, numVertices, startVertex, visitedDFS);
    printf("\n");
    printf("Enter the starting vertex for BFS: ");
    scanf("%d", &startVertex);
    printf("BFS traversal: ");
    bfs(adjacencyMatrix, numVertices, startVertex);
    printf("\n");
    return 0;
}
