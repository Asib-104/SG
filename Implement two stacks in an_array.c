#include <stdio.h>
#define MAX_SIZE 10

int arr[MAX_SIZE];
int top1 = -1;
int top2 = MAX_SIZE;

void push1(int data) {
    if (top1 < top2 - 1) {
        arr[++top1] = data;
    } else {
        printf("Stack Overflow\n");
    }
}

void push2(int data) {
    if (top1 < top2 - 1) {
        arr[--top2] = data;
    } else {
        printf("Stack Overflow\n");
    }
}

int pop1() {
    if (top1 >= 0) {
        return arr[top1--];
    } else {
        printf("Stack Underflow\n");
        return -1;
    }
}

int pop2() {
    if (top2 < MAX_SIZE) {
        return arr[top2++];
    } else {
        printf("Stack Underflow\n");
        return -1;
    }
}

int main() {
    push1(1);
    push1(2);
    push1(3);
    push2(4);
    push2(5);
    push2(6);

    printf("Popped element from stack 1: %d\n", pop1());
    printf("Popped element from stack 2: %d\n", pop2());

    return 0;
}