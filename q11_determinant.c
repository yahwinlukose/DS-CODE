#include <stdio.h>

// Function to calculate determinant of 3x3 matrix
int determinant3x3(int a[3][3]) {
    int det;

    // Apply formula:
    // det = a(ei - fh) - b(di - fg) + c(dh - eg)

    det = a[0][0] * (a[1][1] * a[2][2] - a[1][2] * a[2][1])
        - a[0][1] * (a[1][0] * a[2][2] - a[1][2] * a[2][0])
        + a[0][2] * (a[1][0] * a[2][1] - a[1][1] * a[2][0]);

    return det;
}

int main() {
    int a[3][3]; // 3x3 matrix
    int i, j;

    // --- Read matrix from user ---
    printf("Enter elements of 3x3 matrix:\n");
    for(i = 0; i < 3; i++) {             // Loop for rows
        for(j = 0; j < 3; j++) {         // Loop for columns
            scanf("%d", &a[i][j]);       // Read element
        }
    }

    // --- Call function to calculate determinant ---
    int det = determinant3x3(a);

    // --- Display result ---
    printf("Determinant of the matrix = %d\n", det);

    return 0;
}

