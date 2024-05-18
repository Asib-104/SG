#include <stdio.h>
#define MAX_SIZE 10

int stack[MAX_SIZE];
int top1 = -1; // top index of stack 1
int top2 = MAX_SIZE; // top index of stack 2

// Push operation for stack 1
void push1(int data) {
    if (top1 < top2 - 1) {
        stack[++top1] = data;
    } else {
        printf("Stack Overflow\n");
    }
}

// Push operation for stack 2
void push2(int data) {
    if (top1 < top2 - 1) {
        stack[--top2] = data;
    } else {
        printf("Stack Overflow\n");
    }
}

// Pop operation for stack 1
int pop1() {
    if (top1 >= 0) {
        return stack[top1--];
    } else {
        printf("Stack Underflow\n");
        return -1;
    }
}

// Pop operation for stack 2
int pop2() {
    if (top2 < MAX_SIZE) {
        return stack[top2++];
    } else {
        printf("Stack Underflow\n");
        return -1;
    }
}

int main() {
    push1(1);
    push1(2);
    push2(3);
    push2(4);

    printf("Popped element from stack 1: %d\n", pop1());
    printf("Popped element from stack 2: %d\n", pop2());

    return 0;
}