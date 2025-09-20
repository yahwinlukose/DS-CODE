#include <stdio.h>

// Function to push an element onto the stack
int push(int n, int a[], int top) {
    if (top + 1 == 5) { // Check if the stack is full (size limit is 5)
        printf("Error: Stack is full\n");
        return 4; // Return top as 4 (last valid index)
    }
    a[++top] = n; // Increment top and insert element at new top
    return top;   // Return updated top
}

// Function to pop the top element from the stack
int pop(int a[], int top) {
    if (top == -1) { // Stack is empty
        printf("Error: Stack is empty\n");
        return -1;
    }
    printf("%d removed\n", a[top--]); // Print and remove the top element
    return top; // Return updated top
}

// Function to display all elements of the stack
void display(int a[], int top) {
    int i;
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack elements are:\n");
    for (i = 0; i <= top; i++) {
        printf("%d\t", a[i]); // Print all elements from bottom to top
    }
    printf("\n");
}

// Function to show the top element without removing it
void peek(int a[], int top) {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Top element is: %d\n", a[top]); // Print the top element
}

// Function to display the menu and get user choice
int menu() {
    int input;
    printf("\n---- STACK MENU ----\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Peek (View Top Element)\n");
    printf("4. Display All\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &input); // Read user choice
    return input;
}

// Function to process stack operations based on user input
void processArray(int a[], int top) {
    int ch;

    // Loop until user chooses to exit
    for (ch = menu(); ch != 5; ch = menu()) {
        switch (ch) {
            case 1: {
                int num;
                printf("Enter element to push: ");
                scanf("%d", &num); // Read number to be pushed
                top = push(num, a, top); // Call push function
                break;
            }
            case 2:
                top = pop(a, top); // Call pop function
                break;
            case 3:
                peek(a, top); // Call peek function
                break;
            case 4:
                display(a, top); // Call display function
                break;
            default:
                printf("Wrong choice. Please enter 1 to 5.\n");
        }
    }
}

// Main function to start the program
int main() {
    int a[5];      // Stack array with fixed size 5
    int top = -1;  // Initialize top as -1 indicating empty stack

    processArray(a, top); // Start processing stack operations
    return 0;
}

