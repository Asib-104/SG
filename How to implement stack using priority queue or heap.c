#include <stdio.h>
#include <stdlib.h>

// Structure to represent the stack
typedef struct {
    int* heap;
    int size;
    int capacity;
} Stack;

// Function to initialize the stack
Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->heap = (int*)malloc(capacity * sizeof(int));
    stack->size = 0;
    stack->capacity = capacity;
    return stack;
}

// Function to push an element into the stack
void push(Stack* stack, int element) {
    if (stack->size == stack->capacity) {
        printf("Stack overflow\n");
        return;
    }
    stack->heap[stack->size++] = element;
}

// Function to pop the top element from the stack
void pop(Stack* stack) {
    if (stack->size == 0) {
        printf("Stack underflow\n");
        return;
    }
    stack->size--;
}

// Function to get the top element from the stack
int top(Stack* stack) {
    if (stack->size == 0) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->heap[stack->size - 1];
}

// Function to check if the stack is empty
int isEmpty(Stack* stack) {
    return stack->size == 0;
}

int main() {
    Stack* stack = createStack(5);

    push(stack, 1);
    push(stack, 2);
    push(stack, 3);

    printf("Top element: %d\n", top(stack));

    pop(stack);

    printf("Top element: %d\n", top(stack));

    pop(stack);
    pop(stack);

    if (isEmpty(stack)) {
        printf("Stack is empty\n");
    }

    free(stack->heap);
    free(stack);

    return 0;
}