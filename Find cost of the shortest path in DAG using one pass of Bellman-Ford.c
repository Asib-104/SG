#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Structure to represent a directed edge
struct Edge {
    int source, destination, weight;
};

// Function to find the cost of the shortest path in a DAG using one pass of Bellman-Ford
void shortestPathDAG(int vertices, int source, struct Edge* edges, int edgeCount) {
    int* distance = (int*)malloc(vertices * sizeof(int));

    // Initialize distance array
    for (int i = 0; i < vertices; i++) {
        distance[i] = INT_MAX;
    }
    distance[source] = 0;

    // Relax all edges in topological order
    for (int i = 0; i < vertices - 1; i++) {
        for (int j = 0; j < edgeCount; j++) {
            int u = edges[j].source;
            int v = edges[j].destination;
            int weight = edges[j].weight;
            if (distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
            }
        }
    }

    // Print the shortest path distances
    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < vertices; i++) {
        printf("%d\t%d\n", i, distance[i]);
    }

    free(distance);
}

int main() {
    int vertices = 6;
    int source = 0;
    int edgeCount = 8;
    struct Edge edges[] = {
        {0, 1, 2},
        {0, 2, 3},
        {1, 3, 4},
        {1, 4, 1},
        {2, 3, 1},
        {2, 4, 2},
        {3, 5, 3},
        {4, 5, 2}
    };

    shortestPathDAG(vertices, source, edges, edgeCount);

    return 0;
}