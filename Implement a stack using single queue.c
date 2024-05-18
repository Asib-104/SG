#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the queue
struct Node {
    int data;
    struct Node* next;
};

// Structure to represent the stack
struct Stack {
    struct Node* front;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a new stack
struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->front = NULL;
    return stack;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return (stack->front == NULL);
}

// Function to push an element onto the stack
void push(struct Stack* stack, int data) {
    // Create a new node
    struct Node* newNode = createNode(data);

    // If the stack is empty, make the new node as the front
    if (isEmpty(stack)) {
        stack->front = newNode;
    }
    else {
        // Get the current front of the queue
        struct Node* currentFront = stack->front;

        // Move all elements from the front to the rear of the queue
        while (currentFront->next != NULL) {
            struct Node* temp = currentFront->next;
            currentFront->next = temp->next;
            temp->next = stack->front;
            stack->front = temp;
        }

        // Add the new node at the front
        newNode->next = stack->front;
        stack->front = newNode;
    }
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    // If the stack is empty, return -1
    if (isEmpty(stack)) {
        return -1;
    }

    // Get the front of the queue
    struct Node* front = stack->front;

    // Update the front of the queue
    stack->front = front->next;

    // Get the data of the front node
    int data = front->data;

    // Free the memory of the front node
    free(front);

    // Return the popped element
    return data;
}

// Function to get the top element of the stack without removing it
int top(struct Stack* stack) {
    // If the stack is empty, return -1
    if (isEmpty(stack)) {
        return -1;
    }

    // Return the data of the front node
    return stack->front->data;
}

// Function to display the elements of the stack
void display(struct Stack* stack) {
    // If the stack is empty, print "Stack is empty"
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }

    // Print the elements of the stack
    struct Node* current = stack->front;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Main function
int main() {
    // Create a new stack
    struct Stack* stack = createStack();

    // Push elements onto the stack
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);

    // Display the elements of the stack
    printf("Stack: ");
    display(stack);

    // Pop an element from the stack
    int poppedElement = pop(stack);
    printf("Popped Element: %d\n", poppedElement);

    // Display the elements of the stack
    printf("Stack: ");
    display(stack);

    // Get the top element of the stack
    int topElement = top(stack);
    printf("Top Element: %d\n", topElement);

    return 0;
}