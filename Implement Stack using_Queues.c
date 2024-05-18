#include <stdio.h>
#include <stdlib.h>

// Structure representing a queue node
struct QueueNode {
    int data;
    struct QueueNode* next;
};

// Structure representing a queue
struct Queue {
    struct QueueNode* front;
    struct QueueNode* rear;
};

// Function to create a new queue node
struct QueueNode* createNode(int data) {
    struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create an empty queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

// Function to check if a queue is empty
int isEmpty(struct Queue* queue) {
    return (queue->front == NULL);
}

// Function to enqueue an element to the queue
void enqueue(struct Queue* queue, int data) {
    struct QueueNode* newNode = createNode(data);
    if (isEmpty(queue)) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// Function to dequeue an element from the queue
int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return -1;
    }
    struct QueueNode* temp = queue->front;
    int data = temp->data;
    queue->front = queue->front->next;
    free(temp);
    return data;
}

// Function to push an element to the stack
void push(struct Queue* queue, int data) {
    enqueue(queue, data);
}

// Function to pop an element from the stack
int pop(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Stack is empty.\n");
        return -1;
    }
    struct QueueNode* temp = queue->front;
    while (temp->next != queue->rear) {
        enqueue(queue, dequeue(queue));
        temp = temp->next;
    }
    int data = dequeue(queue);
    queue->rear = temp;
    return data;
}

// Function to get the top element of the stack
int top(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Stack is empty.\n");
        return -1;
    }
    struct QueueNode* temp = queue->front;
    while (temp->next != queue->rear) {
        enqueue(queue, dequeue(queue));
        temp = temp->next;
    }
    int data = dequeue(queue);
    enqueue(queue, data);
    queue->rear = temp;
    return data;
}

// Function to display the stack elements
void display(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Stack is empty.\n");
        return;
    }
    struct QueueNode* temp = queue->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Queue* stack = createQueue();

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    printf("Stack elements: ");
    display(stack);

    printf("Top element: %d\n", top(stack));

    printf("Popped element: %d\n", pop(stack));

    printf("Stack elements after popping: ");
    display(stack);

    return 0;
}