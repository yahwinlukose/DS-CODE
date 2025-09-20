#include <stdio.h>

// Function to compare two strings manually
int compare(char s1[], char s2[]) {
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] < s2[i])
            return -1; // s1 comes before s2
        else if (s1[i] > s2[i])
            return 1;  // s1 comes after s2
        i++;
    }

    // If all characters matched so far, shorter string is smaller
    if (s1[i] == '\0' && s2[i] == '\0')
        return 0; // Both are equal
    else if (s1[i] == '\0')
        return -1; // s1 is shorter, so comes first
    else
        return 1;  // s2 is shorter, so s1 comes after
}

// Function to copy one string to another manually
void copy(char dest[], char src[]) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0'; // Add null terminator at end
}

int main() {
    char str[10][100], temp[100];
    int n, i, j;

    // --- Read number of strings ---
    printf("Enter number of strings (max 10): ");
    scanf("%d", &n);
    getchar(); // Clear newline after scanf

    // --- Read n strings from user ---
    printf("Enter %d strings:\n", n);
    for (i = 0; i < n; i++) {
        int ch, k = 0;
        while ((ch = getchar()) != '\n') {
            str[i][k++] = ch; // Read each character
        }
        str[i][k] = '\0'; // Null-terminate the string
    }

    // --- Sort using bubble sort ---
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (compare(str[i], str[j]) > 0) {
                // Swap str[i] and str[j] manually
                copy(temp, str[i]);
                copy(str[i], str[j]);
                copy(str[j], temp);
            }
        }
    }

    // --- Display sorted strings ---
    printf("\nStrings in ascending order:\n");
    for (i = 0; i < n; i++) {
        printf("%s\n", str[i]);
    }

    return 0;
}

