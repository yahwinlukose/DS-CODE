#include <stdio.h>

#define MAX 30

char infix[MAX], postfix[MAX], stack[MAX];
int top = -1;

int precedence(char op) {
    switch(op) {
        case '^': return 3;  // highest
        case '*':
        case '/':
        case '%': return 2;
        case '+':
        case '-': return 1;
        default: return 0;   // non-operator
    }
}

void push(char c) {
    if (top < MAX - 1) {
        stack[++top] = c;
    }
}

char pop() {
    if (top >= 0) {
        return stack[top--];
    }
    return '\0';
}

char peek() {
    if (top >= 0) return stack[top];
    return '\0';
}

void infixToPostfix() {
    int i = 0, j = 0;
    char ch;

    while (infix[i] != '\0') {
        ch = infix[i];

        // If operand (alphabet or digit), add to postfix
        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9')) {
            postfix[j++] = ch;
        }
        else if (ch == '(') {
            push(ch);
        }
        else if (ch == ')') {
            // Pop until '(' is found
            while (top >= 0 && peek() != '(') {
                postfix[j++] = pop();
            }
            if (top >= 0) pop(); // discard '('
        }
        else {
            // Operator encountered
            while (top >= 0 && precedence(peek()) >= precedence(ch) && peek() != '(') {
                postfix[j++] = pop();
            }
            push(ch);
        }
        i++;
    }

    // Pop remaining operators
    while (top >= 0) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
}

int main() {
    printf("Enter the infix expression: ");
    scanf("%s", infix);

    infixToPostfix();

    printf("Postfix expression: %s\n", postfix);

    return 0;
}

