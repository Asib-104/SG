#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100

bool visited[MAX_VERTICES];
int graph[MAX_VERTICES][MAX_VERTICES];
int path[MAX_VERTICES];
int pathIndex = 0;

void initializeGraph() {
    for (int i = 0; i < MAX_VERTICES; i++) {
        visited[i] = false;
        for (int j = 0; j < MAX_VERTICES; j++) {
            graph[i][j] = 0;
        }
    }
}

void addEdge(int u, int v) {
    graph[u][v] = 1;
}

bool dfs(int start, int end) {
    visited[start] = true;
    path[pathIndex++] = start;

    if (start == end) {
        // Print the path
        for (int i = 0; i < pathIndex; i++) {
            printf("%d ", path[i]);
        }
        printf("\n");
        return true;
    }

    for (int i = 0; i < MAX_VERTICES; i++) {
        if (graph[start][i] == 1 && !visited[i]) {
            if (dfs(i, end)) {
                return true;
            }
        }
    }

    pathIndex--;
    visited[start] = false;
    return false;
}

int main() {
    initializeGraph();

    // Add edges to the graph
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);
    addEdge(2, 4);
    addEdge(3, 4);
    addEdge(3, 5);
    addEdge(4, 5);

    int startVertex = 0;
    int endVertex = 5;

    printf("Path between %d and %d: ", startVertex, endVertex);
    if (!dfs(startVertex, endVertex)) {
        printf("No path found.\n");
    }

    return 0;
}