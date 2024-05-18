#include <stdio.h>
#include <stdlib.h>

// Structure for a node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Structure for Deque
struct Deque {
    struct Node* front;
    struct Node* rear;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize a Deque
void initializeDeque(struct Deque* deque) {
    deque->front = NULL;
    deque->rear = NULL;
}

// Function to check if the Deque is empty
int isEmpty(struct Deque* deque) {
    return (deque->front == NULL);
}

// Function to insert an element at the front of the Deque
void insertFront(struct Deque* deque, int data) {
    struct Node* newNode = createNode(data);
    if (isEmpty(deque)) {
        deque->front = newNode;
        deque->rear = newNode;
    } else {
        newNode->next = deque->front;
        deque->front->prev = newNode;
        deque->front = newNode;
    }
    printf("Element %d inserted at the front of the Deque.\n", data);
}

// Function to insert an element at the rear of the Deque
void insertRear(struct Deque* deque, int data) {
    struct Node* newNode = createNode(data);
    if (isEmpty(deque)) {
        deque->front = newNode;
        deque->rear = newNode;
    } else {
        newNode->prev = deque->rear;
        deque->rear->next = newNode;
        deque->rear = newNode;
    }
    printf("Element %d inserted at the rear of the Deque.\n", data);
}

// Function to delete an element from the front of the Deque
void deleteFront(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty. Cannot delete from front.\n");
        return;
    }
    struct Node* temp = deque->front;
    deque->front = deque->front->next;
    if (deque->front == NULL) {
        deque->rear = NULL;
    } else {
        deque->front->prev = NULL;
    }
    printf("Element %d deleted from the front of the Deque.\n", temp->data);
    free(temp);
}

// Function to delete an element from the rear of the Deque
void deleteRear(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty. Cannot delete from rear.\n");
        return;
    }
    struct Node* temp = deque->rear;
    deque->rear = deque->rear->prev;
    if (deque->rear == NULL) {
        deque->front = NULL;
    } else {
        deque->rear->next = NULL;
    }
    printf("Element %d deleted from the rear of the Deque.\n", temp->data);
    free(temp);
}

// Function to display the elements of the Deque
void display(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty.\n");
        return;
    }
    struct Node* current = deque->front;
    printf("Elements of the Deque: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Main function
int main() {
    struct Deque deque;
    initializeDeque(&deque);

    insertFront(&deque, 10);
    insertFront(&deque, 20);
    insertRear(&deque, 30);
    insertRear(&deque, 40);

    display(&deque);

    deleteFront(&deque);
    deleteRear(&deque);

    display(&deque);

    return 0;
}