#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

// Structure to represent a node in the graph
typedef struct Node {
    int value;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// Function to add an edge to the graph
void addEdge(Node* graph[], int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph[src];
    graph[src] = newNode;
}

// Function to perform topological sorting
void topologicalSortUtil(Node* graph[], int node, int visited[], int stack[], int* top) {
    visited[node] = 1;

    Node* temp = graph[node];
    while (temp != NULL) {
        if (!visited[temp->value]) {
            topologicalSortUtil(graph, temp->value, visited, stack, top);
        }
        temp = temp->next;
    }

    stack[++(*top)] = node;
}

// Function to find the longest path in a DAG
void findLongestPath(Node* graph[], int numNodes, int startNode) {
    int visited[MAX_NODES] = {0};
    int stack[MAX_NODES];
    int top = -1;

    for (int i = 0; i < numNodes; i++) {
        if (!visited[i]) {
            topologicalSortUtil(graph, i, visited, stack, &top);
        }
    }

    int dist[MAX_NODES];
    for (int i = 0; i < numNodes; i++) {
        dist[i] = INT_MIN;
    }
    dist[startNode] = 0;

    while (top >= 0) {
        int node = stack[top--];

        if (dist[node] != INT_MIN) {
            Node* temp = graph[node];
            while (temp != NULL) {
                if (dist[temp->value] < dist[node] + 1) {
                    dist[temp->value] = dist[node] + 1;
                }
                temp = temp->next;
            }
        }
    }

    int longestPath = 0;
    for (int i = 0; i < numNodes; i++) {
        if (dist[i] > longestPath) {
            longestPath = dist[i];
        }
    }

    printf("The longest path in the DAG is: %d\n", longestPath);
}

int main() {
    int numNodes = 6;
    Node* graph[MAX_NODES] = {NULL};

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 5);
    addEdge(graph, 4, 5);

    int startNode = 0;
    findLongestPath(graph, numNodes, startNode);

    return 0;
}