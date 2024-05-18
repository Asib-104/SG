#include <stdio.h>
#include <stdbool.h>

#define ROWS 3
#define COLS 3

int max(int a, int b) {
    return (a > b) ? a : b;
}

bool isValid(int x, int y, int prevX, int prevY) {
    return (x >= 0 && x < ROWS && y >= 0 && y < COLS && (x != prevX || y != prevY));
}

int findLongestPath(char matrix[ROWS][COLS], int x, int y, int prevX, int prevY) {
    if (!isValid(x, y, prevX, prevY))
        return 0;

    int length = 1;

    if (matrix[x][y] - matrix[prevX][prevY] == 1) {
        length = max(length, 1 + findLongestPath(matrix, x - 1, y, x, y));
        length = max(length, 1 + findLongestPath(matrix, x + 1, y, x, y));
        length = max(length, 1 + findLongestPath(matrix, x, y - 1, x, y));
        length = max(length, 1 + findLongestPath(matrix, x, y + 1, x, y));
    }

    return length;
}

int main() {
    char matrix[ROWS][COLS] = {
        {'a', 'b', 'c'},
        {'d', 'e', 'f'},
        {'g', 'h', 'i'}
    };

    int maxLength = 0;

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            maxLength = max(maxLength, findLongestPath(matrix, i, j, -1, -1));
        }
    }

    printf("Length of the longest path: %d\n", maxLength);

    return 0;
}