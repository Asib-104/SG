#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

// Structure to represent a node in the graph
struct Node {
    int data;
    struct Node* next;
};

// Structure to represent the graph
struct Graph {
    int numNodes;
    struct Node* adjList[MAX_NODES];
};

// Function to add an edge between two nodes in the graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Create a new node for the destination
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = dest;
    newNode->next = NULL;

    // Add the new node to the adjacency list of the source node
    if (graph->adjList[src] == NULL) {
        graph->adjList[src] = newNode;
    } else {
        struct Node* temp = graph->adjList[src];
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Create a new node for the source
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = src;
    newNode->next = NULL;

    // Add the new node to the adjacency list of the destination node
    if (graph->adjList[dest] == NULL) {
        graph->adjList[dest] = newNode;
    } else {
        struct Node* temp = graph->adjList[dest];
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to check if there is a cycle in the graph using BFS
int hasCycle(struct Graph* graph, int startNode) {
    int visited[MAX_NODES] = {0};
    int parent[MAX_NODES] = {-1};

    // Create a queue for BFS
    int queue[MAX_NODES];
    int front = 0, rear = 0;

    // Mark the start node as visited and enqueue it
    visited[startNode] = 1;
    queue[rear++] = startNode;

    while (front != rear) {
        // Dequeue a node from the queue
        int currentNode = queue[front++];
        struct Node* temp = graph->adjList[currentNode];

        // Traverse all the adjacent nodes of the current node
        while (temp != NULL) {
            int adjNode = temp->data;

            // If the adjacent node is not visited, mark it as visited and enqueue it
            if (!visited[adjNode]) {
                visited[adjNode] = 1;
                queue[rear++] = adjNode;
                parent[adjNode] = currentNode;
            }
            // If the adjacent node is visited and not the parent of the current node, then there is a cycle
            else if (adjNode != parent[currentNode]) {
                return 1;
            }

            temp = temp->next;
        }
    }

    return 0;
}

int main() {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numNodes = 5;

    // Initialize the adjacency list
    for (int i = 0; i < MAX_NODES; i++) {
        graph->adjList[i] = NULL;
    }

    // Add edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 0);

    // Check if there is a cycle in the graph
    if (hasCycle(graph, 0)) {
        printf("Cycle detected in the graph.\n");
    } else {
        printf("No cycle detected in the graph.\n");
    }

    return 0;
}