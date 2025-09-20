#include <stdio.h>

void main() {
    char str[100];  // Array to store the string (max 100 characters)
    int i = 0, length = 0;

    // Read the string from the user
    printf("Enter a string: ");
    scanf("%s", str);  // Reads string until space or newline

    // Calculate the length of the string
    while(str[length] != '\0') {
        length++;
    }

    // Print the string in reverse order
    printf("Reversed string: ");
    for(i = length - 1; i >= 0; i--) {
        printf("%c", str[i]);  // Print each character from the end
    }

    printf("\n");  // Newline at the end
}

