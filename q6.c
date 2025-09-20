#include <stdio.h>

// Recursive function to print array elements
void show(int a[], int i) {
    if (i >= 5)    // Base case: Stop when index reaches size of array
        return;
    
    printf("%d ", a[i]);   // Print the current element
    show(a, i + 1);        // Recursive call with next index
}

void main() {
    int a[10] = {1, 2, 3, 4, 5};  // Initialize array
    show(a, 0);                   // Start recursion from index 0
}

