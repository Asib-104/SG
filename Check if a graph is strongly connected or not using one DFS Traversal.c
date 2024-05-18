#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Function to perform DFS traversal
void dfs(int graph[MAX_SIZE][MAX_SIZE], int visited[MAX_SIZE], int v, int n) {
    visited[v] = 1;
    
    for (int i = 0; i < n; i++) {
        if (graph[v][i] && !visited[i]) {
            dfs(graph, visited, i, n);
        }
    }
}

// Function to check if a graph is strongly connected
bool isStronglyConnected(int graph[MAX_SIZE][MAX_SIZE], int n) {
    int visited[MAX_SIZE] = {0};
    
    // Perform DFS traversal from the first vertex
    dfs(graph, visited, 0, n);
    
    // Check if all vertices are visited
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            return false;
        }
    }
    
    // Transpose the graph
    int transposedGraph[MAX_SIZE][MAX_SIZE];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            transposedGraph[i][j] = graph[j][i];
        }
    }
    
    // Reset visited array
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }
    
    // Perform DFS traversal from the first vertex in the transposed graph
    dfs(transposedGraph, visited, 0, n);
    
    // Check if all vertices are visited
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            return false;
        }
    }
    
    return true;
}

int main() {
    int n;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &n);
    
    int graph[MAX_SIZE][MAX_SIZE];
    printf("Enter the adjacency matrix of the graph:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    
    if (isStronglyConnected(graph, n)) {
        printf("The graph is strongly connected.\n");
    } else {
        printf("The graph is not strongly connected.\n");
    }
    
    return 0;
}