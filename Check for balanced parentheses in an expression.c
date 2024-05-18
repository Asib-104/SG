#include <stdio.h>
#include <stdbool.h>

bool isBalanced(char* expression) {
    int count = 0;
    for (int i = 0; expression[i] != '\0'; i++) {
        if (expression[i] == '(') {
            count++;
        } else if (expression[i] == ')') {
            count--;
            if (count < 0) {
                return false;
            }
        }
    }
    return count == 0;
}

int main() {
    char expression[100];
    printf("Enter an expression: ");
    scanf("%s", expression);

    if (isBalanced(expression)) {
        printf("The expression is balanced.\n");
    } else {
        printf("The expression is not balanced.\n");
    }

    return 0;
}