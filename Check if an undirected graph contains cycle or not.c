#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100

bool visited[MAX_VERTICES];
int graph[MAX_VERTICES][MAX_VERTICES];

bool isCyclicUtil(int v, int parent, int V) {
    visited[v] = true;

    for (int i = 0; i < V; i++) {
        if (graph[v][i]) {
            if (!visited[i]) {
                if (isCyclicUtil(i, v, V))
                    return true;
            } else if (i != parent) {
                return true;
            }
        }
    }

    return false;
}

bool isCyclic(int V) {
    for (int i = 0; i < V; i++) {
        visited[i] = false;
    }

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (isCyclicUtil(i, -1, V))
                return true;
        }
    }

    return false;
}

int main() {
    int V;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    if (isCyclic(V)) {
        printf("The graph contains a cycle.\n");
    } else {
        printf("The graph does not contain a cycle.\n");
    }

    return 0;
}