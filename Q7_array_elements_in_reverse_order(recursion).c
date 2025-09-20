#include <stdio.h>

// Recursive function to print array elements from index i to 0
void show(int a[], int i) {
    if (i < 0) // Base case: stop when index becomes negative
        return;

    printf("%d ", a[i]);  // Print the current element
    show(a, i - 1);       // Recursive call to go to the previous index
}

void main() {
    int a[10] = {1, 2, 3, 4, 5};  // Initialize array with first 5 elements
    show(a, 4);                   // Start recursion from index 4 (prints 5 to 1)
}

