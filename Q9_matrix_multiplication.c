#include <stdio.h>

int main() {
    // Declare three 3x3 matrices: A, B, and C
    int A[3][3], B[3][3], C[3][3];
    int i, j, k; // Loop variables

    // -------- Input Matrix A --------
    printf("Enter elements of matrix A (3x3):\n");
    for(i = 0; i < 3; i++) {              // Loop through rows
        for(j = 0; j < 3; j++) {          // Loop through columns
            scanf("%d", &A[i][j]);        // Read element into A[i][j]
        }
    }

    // -------- Input Matrix B --------
    printf("Enter elements of matrix B (3x3):\n");
    for(i = 0; i < 3; i++) {              // Loop through rows
        for(j = 0; j < 3; j++) {          // Loop through columns
            scanf("%d", &B[i][j]);        // Read element into B[i][j]
        }
    }

    // -------- Multiply A and B to get C --------
    for(i = 0; i < 3; i++) {              // Loop through rows of A
        for(j = 0; j < 3; j++) {          // Loop through columns of B
            C[i][j] = 0;                  // Initialize result element
            for(k = 0; k < 3; k++) {      // Loop through elements of row A and column B
                C[i][j] += A[i][k] * B[k][j];  // Multiply and accumulate
            }
        }
    }

    // -------- Output Resultant Matrix C --------
    printf("Resultant matrix C (A * B):\n");
    for(i = 0; i < 3; i++) {              // Loop through rows
        for(j = 0; j < 3; j++) {          // Loop through columns
            printf("%d\t", C[i][j]);      // Print element
        }
        printf("\n");                     // Newline after each row
    }

    return 0; // Exit the program
}

