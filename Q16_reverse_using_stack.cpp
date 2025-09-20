#include <stdio.h>
#include <string.h>

#define MAX 100

// Stack implementation
char stack[MAX];
int top = -1;

void push(char c) {
    if (top < MAX - 1) {
        stack[++top] = c;
    }
}

char pop() {
    if (top >= 0) {
        return stack[top--];
    }
    return '\0';  // Return null char if stack is empty
}

void reverseString(char* str) {
    int i;
    // Push all characters to stack
    for (i = 0; str[i] != '\0'; i++) {
        push(str[i]);
    }

    // Pop characters from stack back into the string
    for (i = 0; str[i] != '\0'; i++) {
        str[i] = pop();
    }
}

int main() {
    char str[MAX];

    printf("Enter a string: ");
    fgets(str, MAX, stdin);

    // Remove newline character if present
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }

    reverseString(str);
    printf("Reversed string: %s\n", str);

    return 0;
}

