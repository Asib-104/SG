#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the cache
typedef struct Node {
    int key;
    int value;
    struct Node* prev;
    struct Node* next;
} Node;

// Structure to represent the LRU cache
typedef struct LRUCache {
    int capacity;
    int size;
    Node* head;
    Node* tail;
} LRUCache;

// Function to create a new node
Node* createNode(int key, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize the LRU cache
LRUCache* createLRUCache(int capacity) {
    LRUCache* cache = (LRUCache*)malloc(sizeof(LRUCache));
    cache->capacity = capacity;
    cache->size = 0;
    cache->head = NULL;
    cache->tail = NULL;
    return cache;
}

// Function to remove a node from the cache
void removeNode(LRUCache* cache, Node* node) {
    if (node->prev != NULL) {
        node->prev->next = node->next;
    } else {
        cache->head = node->next;
    }
    if (node->next != NULL) {
        node->next->prev = node->prev;
    } else {
        cache->tail = node->prev;
    }
    free(node);
}

// Function to add a node to the front of the cache
void addToFront(LRUCache* cache, Node* node) {
    node->next = cache->head;
    node->prev = NULL;
    if (cache->head != NULL) {
        cache->head->prev = node;
    }
    cache->head = node;
    if (cache->tail == NULL) {
        cache->tail = node;
    }
}

// Function to get the value associated with a key from the cache
int get(LRUCache* cache, int key) {
    Node* node = cache->head;
    while (node != NULL) {
        if (node->key == key) {
            // Move the node to the front of the cache
            removeNode(cache, node);
            addToFront(cache, node);
            return node->value;
        }
        node = node->next;
    }
    return -1; // Key not found in cache
}

// Function to put a key-value pair into the cache
void put(LRUCache* cache, int key, int value) {
    Node* node = cache->head;
    while (node != NULL) {
        if (node->key == key) {
            // Update the value of the existing node
            node->value = value;
            // Move the node to the front of the cache
            removeNode(cache, node);
            addToFront(cache, node);
            return;
        }
        node = node->next;
    }
    if (cache->size == cache->capacity) {
        // Remove the least recently used node from the cache
        Node* tailNode = cache->tail;
        removeNode(cache, tailNode);
        cache->size--;
    }
    // Add the new node to the front of the cache
    Node* newNode = createNode(key, value);
    addToFront(cache, newNode);
    cache->size++;
}

// Function to print the contents of the cache
void printCache(LRUCache* cache) {
    Node* node = cache->head;
    while (node != NULL) {
        printf("(%d, %d) ", node->key, node->value);
        node = node->next;
    }
    printf("\n");
}

int main() {
    // Create a cache with capacity 3
    LRUCache* cache = createLRUCache(3);

    // Put some key-value pairs into the cache
    put(cache, 1, 10);
    put(cache, 2, 20);
    put(cache, 3, 30);

    // Print the contents of the cache
    printCache(cache); // Output: (3, 30) (2, 20) (1, 10)

    // Get the value associated with key 2
    int value = get(cache, 2);
    printf("Value of key 2: %d\n", value); // Output: Value of key 2: 20

    // Put a new key-value pair into the cache
    put(cache, 4, 40);

    // Print the contents of the cache
    printCache(cache); // Output: (4, 40) (3, 30) (2, 20)

    return 0;
}