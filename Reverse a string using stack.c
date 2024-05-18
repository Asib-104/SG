#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100

// Structure to represent a stack
typedef struct {
    int top;
    char data[MAX_SIZE];
} Stack;

// Function to initialize the stack
void initialize(Stack* stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Function to push an element onto the stack
void push(Stack* stack, char element) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack->data[++stack->top] = element;
}

// Function to pop an element from the stack
char pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return '\0';
    }
    return stack->data[stack->top--];
}

// Function to reverse a string using a stack
void reverseString(char* str) {
    int length = strlen(str);
    Stack stack;
    initialize(&stack);

    // Push each character of the string onto the stack
    for (int i = 0; i < length; i++) {
        push(&stack, str[i]);
    }

    // Pop each character from the stack and store it back in the string
    for (int i = 0; i < length; i++) {
        str[i] = pop(&stack);
    }
}

int main() {
    char str[MAX_SIZE];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove the newline character from the input
    str[strcspn(str, "\n")] = '\0';

    // Reverse the string
    reverseString(str);

    printf("Reversed string: %s\n", str);

    return 0;
}