#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Structure to represent a stack
typedef struct {
    int arr[MAX_SIZE];
    int top;
} Stack;

// Function to initialize a stack
void initialize(Stack* stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Function to check if the stack is full
int isFull(Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

// Function to push an element onto the stack
void push(Stack* stack, int data) {
    if (isFull(stack)) {
        printf("Stack overflow!\n");
        return;
    }
    stack->arr[++stack->top] = data;
}

// Function to pop an element from the stack
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow!\n");
        return -1;
    }
    return stack->arr[stack->top--];
}

// Function to insert an element at the bottom of the stack
void insertAtBottom(Stack* stack, int data) {
    if (isEmpty(stack)) {
        push(stack, data);
    } else {
        int temp = pop(stack);
        insertAtBottom(stack, data);
        push(stack, temp);
    }
}

// Function to reverse a stack using recursion
void reverseStack(Stack* stack) {
    if (!isEmpty(stack)) {
        int temp = pop(stack);
        reverseStack(stack);
        insertAtBottom(stack, temp);
    }
}

// Function to print the stack
void printStack(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack: ");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->arr[i]);
    }
    printf("\n");
}

int main() {
    Stack stack;
    initialize(&stack);

    // Push elements onto the stack
    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);
    push(&stack, 4);
    push(&stack, 5);

    printf("Before reversing:\n");
    printStack(&stack);

    // Reverse the stack
    reverseStack(&stack);

    printf("After reversing:\n");
    printStack(&stack);

    return 0;
}