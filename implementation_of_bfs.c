#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Queue data structure
typedef struct {
    int items[MAX_SIZE];
    int front;
    int rear;
} Queue;

// Graph data structure
typedef struct {
    int vertices;
    int adjMatrix[MAX_SIZE][MAX_SIZE];
} Graph;

// Queue operations
void enqueue(Queue* q, int value) {
    if (q->rear == MAX_SIZE - 1) {
        printf("Queue is full\n");
    } else {
        if (q->front == -1) {
            q->front = 0;
        }
        q->rear++;
        q->items[q->rear] = value;
    }
}

int dequeue(Queue* q) {
    int item;
    if (q->front == -1 || q->front > q->rear) {
        printf("Queue is empty\n");
        item = -1;
    } else {
        item = q->items[q->front];
        q->front++;
    }
    return item;
}

bool isEmpty(Queue* q) {
    if (q->front == -1 || q->front > q->rear) {
        return true;
    }
    return false;
}

// BFS algorithm
void bfs(Graph* graph, int startVertex, bool visited[]) {
    Queue q;
    q.front = -1;
    q.rear = -1;

    // Mark the start vertex as visited and enqueue it
    visited[startVertex] = true;
    enqueue(&q, startVertex);

    while (!isEmpty(&q)) {
        int currentVertex = dequeue(&q);
        printf("%d ", currentVertex);

        // Visit all the adjacent vertices of the current vertex
        for (int i = 0; i < graph->vertices; i++) {
            if (graph->adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = true;
                enqueue(&q, i);
            }
        }
    }
}

int main() {
    Graph graph;
    int vertices;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    graph.vertices = vertices;

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            scanf("%d", &graph.adjMatrix[i][j]);
        }
    }

    bool visited[MAX_SIZE];
    for (int i = 0; i < MAX_SIZE; i++) {
        visited[i] = false;
    }

    printf("BFS traversal: ");
    bfs(&graph, 0, visited);

    return 0;
}