#include <stdio.h>
#include <stdlib.h>

// Structure for stack node
struct StackNode {
    int data;
    struct StackNode* next;
};

// Structure for stack
struct Stack {
    struct StackNode* top;
};

// Function to create a new stack node
struct StackNode* createNode(int data) {
    struct StackNode* newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to check if stack is empty
int isEmpty(struct Stack* stack) {
    return (stack->top == NULL);
}

// Function to push an element to stack
void push(struct Stack** stack, int data) {
    struct StackNode* newNode = createNode(data);
    newNode->next = (*stack)->top;
    (*stack)->top = newNode;
}

// Function to pop an element from stack
int pop(struct Stack** stack) {
    if (isEmpty(*stack)) {
        printf("Stack is empty.\n");
        return -1;
    }
    struct StackNode* temp = (*stack)->top;
    int data = temp->data;
    (*stack)->top = (*stack)->top->next;
    free(temp);
    return data;
}

// Function to enqueue an element to queue
void enqueue(struct Stack** stack1, struct Stack** stack2, int data) {
    while (!isEmpty(*stack1)) {
        push(stack2, pop(stack1));
    }
    push(stack1, data);
    while (!isEmpty(*stack2)) {
        push(stack1, pop(stack2));
    }
}

// Function to dequeue an element from queue
int dequeue(struct Stack** stack1) {
    if (isEmpty(*stack1)) {
        printf("Queue is empty.\n");
        return -1;
    }
    return pop(stack1);
}

// Function to print the queue
void printQueue(struct Stack* stack1) {
    struct StackNode* temp = stack1->top;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Driver code
int main() {
    struct Stack* stack1 = (struct Stack*)malloc(sizeof(struct Stack));
    struct Stack* stack2 = (struct Stack*)malloc(sizeof(struct Stack));
    stack1->top = NULL;
    stack2->top = NULL;

    enqueue(&stack1, &stack2, 1);
    enqueue(&stack1, &stack2, 2);
    enqueue(&stack1, &stack2, 3);

    printf("Queue: ");
    printQueue(stack1);

    printf("Dequeued element: %d\n", dequeue(&stack1));

    printf("Queue after dequeue: ");
    printQueue(stack1);

    return 0;
}