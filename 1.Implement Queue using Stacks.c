#include <stdio.h>
#include <stdlib.h>

// Structure for stack node
struct StackNode {
    int data;
    struct StackNode* next;
};

// Structure for queue
struct Queue {
    struct StackNode* stack1;
    struct StackNode* stack2;
};

// Function to create a new stack node
struct StackNode* createNode(int data) {
    struct StackNode* newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to push an element to stack
void push(struct StackNode** top, int data) {
    struct StackNode* newNode = createNode(data);
    newNode->next = *top;
    *top = newNode;
}

// Function to pop an element from stack
int pop(struct StackNode** top) {
    if (*top == NULL) {
        printf("Stack is empty\n");
        return -1;
    }
    struct StackNode* temp = *top;
    *top = (*top)->next;
    int popped = temp->data;
    free(temp);
    return popped;
}

// Function to enqueue an element to queue
void enqueue(struct Queue* queue, int data) {
    push(&queue->stack1, data);
}

// Function to dequeue an element from queue
int dequeue(struct Queue* queue) {
    if (queue->stack1 == NULL && queue->stack2 == NULL) {
        printf("Queue is empty\n");
        return -1;
    }
    if (queue->stack2 == NULL) {
        while (queue->stack1 != NULL) {
            int data = pop(&queue->stack1);
            push(&queue->stack2, data);
        }
    }
    int popped = pop(&queue->stack2);
    return popped;
}


// Driver code
int main() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->stack1 = NULL;
    queue->stack2 = NULL;

    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);

    printf("%d ", dequeue(queue));
    printf("%d ", dequeue(queue));
    printf("%d ", dequeue(queue));

    return 0;
}