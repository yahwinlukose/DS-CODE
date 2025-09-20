#include <stdio.h>                 // Include standard input-output header

int a[10] = {1, 2, 1, 3, 4, 5, 1, 6, 5};  // Initialize an array with 9 elements
void main(){
    int i, j;
    int n = 0;                    // 'n' stores the element to search
    int flag = 0;                 // 'flag' counts the number of occurrences

    printf("Enter an element to search: ");
    scanf("%d", &n);             // Read the element to search from user

    for(i = 0; i < 10; i++) {    // Loop through the array
        if(a[i] == n) {          // If the element matches
            flag++;              // Increment count
            printf("Found at index: %d\n", i);  // Print the index where it is found
        }
    }

    printf("Number of occurrences: %d", flag);  // Print total number of times it was found
}
