#include <stdio.h>
#include <string.h>

void reverseWords(char* str) {
    int start = 0;
    int end = 0;
    int length = strlen(str);

    while (end <= length) {
        if (str[end] == ' ' || str[end] == '\0') {
            int i;
            for (i = end - 1; i >= start; i--) {
                printf("%c", str[i]);
            }
            printf(" ");
            start = end + 1;
        }
        end++;
    }
}

int main() {
    char str[] = "Reverse individual words";
    reverseWords(str);
    return 0;
}