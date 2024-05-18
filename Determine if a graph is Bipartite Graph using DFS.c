#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100

int graph[MAX_VERTICES][MAX_VERTICES];
int color[MAX_VERTICES];

bool isBipartite(int v, int c, int n) {
    color[v] = c;

    for (int i = 0; i < n; i++) {
        if (graph[v][i]) {
            if (color[i] == c) {
                return false;
            }
            if (color[i] == 0 && !isBipartite(i, -c, n)) {
                return false;
            }
        }
    }

    return true;
}

bool isBipartiteGraph(int n) {
    for (int i = 0; i < n; i++) {
        color[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        if (color[i] == 0) {
            if (!isBipartite(i, 1, n)) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    int n; // Number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    if (isBipartiteGraph(n)) {
        printf("The graph is a bipartite graph.\n");
    } else {
        printf("The graph is not a bipartite graph.\n");
    }

    return 0;
}