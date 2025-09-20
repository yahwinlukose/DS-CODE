#include<stdio.h>

void main() {
    int a[3][3];  // Original matrix
    int b[3][3];  // Transpose matrix

    int i, j;

    // Input matrix elements from the user
    printf("Enter the matrix elements (3x3):\n");
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    // Compute transpose of the matrix
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            b[j][i] = a[i][j];  // Swap rows and columns
        }
    }

    // Display the original matrix
    printf("Original matrix:\n");
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            printf("%d\t", a[i][j]);  // Tab for spacing
        }
        printf("\n");
    }

    // Display the transpose matrix
    printf("Transpose matrix:\n");
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            printf("%d\t", b[i][j]);  // Tab for spacing
        }
        printf("\n");
    }
}

