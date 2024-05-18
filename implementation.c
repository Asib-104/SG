#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100

// Adjacency matrix representation of the graph
int graph[MAX_VERTICES][MAX_VERTICES];
bool visited[MAX_VERTICES];

// Function to perform Depth First Search
void dfs(int vertex, int numVertices) {
    visited[vertex] = true;
    printf("%d ", vertex);

    for (int i = 0; i < numVertices; i++) {
        if (graph[vertex][i] && !visited[i]) {
            dfs(i, numVertices);
        }
    }
}

int main() {
    int numVertices, numEdges;
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    // Initialize the graph
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            graph[i][j] = 0;
        }
        visited[i] = false;
    }

    // Read the edges of the graph
    printf("Enter the edges (vertex1 vertex2):\n");
    for (int i = 0; i < numEdges; i++) {
        int vertex1, vertex2;
        scanf("%d %d", &vertex1, &vertex2);
        graph[vertex1][vertex2] = 1;
        graph[vertex2][vertex1] = 1;
    }

    int startVertex;
    printf("Enter the starting vertex: ");
    scanf("%d", &startVertex);

    printf("Depth First Traversal: ");
    dfs(startVertex, numVertices);

    return 0;
}