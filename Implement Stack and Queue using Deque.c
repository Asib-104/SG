#include <stdio.h>
#include <stdlib.h>

// Structure for a node
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Structure for a deque
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
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to check if the deque is empty
int isEmpty(struct Deque* deque) {
    return (deque->front == NULL);
}

// Function to insert an element at the front of the deque
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
    printf("%d inserted at the front of the deque.\n", data);
}

// Function to insert an element at the rear of the deque
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
    printf("%d inserted at the rear of the deque.\n", data);
}

// Function to delete an element from the front of the deque
void deleteFront(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty. Cannot delete from front.\n");
    } else {
        struct Node* temp = deque->front;
        deque->front = deque->front->next;
        if (deque->front == NULL) {
            deque->rear = NULL;
        } else {
            deque->front->prev = NULL;
        }
        printf("%d deleted from the front of the deque.\n", temp->data);
        free(temp);
    }
}

// Function to delete an element from the rear of the deque
void deleteRear(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty. Cannot delete from rear.\n");
    } else {
        struct Node* temp = deque->rear;
        deque->rear = deque->rear->prev;
        if (deque->rear == NULL) {
            deque->front = NULL;
        } else {
            deque->rear->next = NULL;
        }
        printf("%d deleted from the rear of the deque.\n", temp->data);
        free(temp);
    }
}

// Function to display the elements of the deque
void display(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty.\n");
    } else {
        struct Node* current = deque->front;
        printf("Elements of the deque: ");
        while (current != NULL) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

int main() {
    struct Deque* deque = (struct Deque*)malloc(sizeof(struct Deque));
    deque->front = NULL;
    deque->rear = NULL;

    insertFront(deque, 10);
    insertFront(deque, 20);
    insertRear(deque, 30);
    insertRear(deque, 40);

    display(deque);

    deleteFront(deque);
    deleteRear(deque);

    display(deque);

    free(deque);

    return 0;
}