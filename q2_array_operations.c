#include <stdio.h>              // Include standard I/O functions
#define SIZE 100                // Define the maximum size of the array

int a[SIZE];                    // Declare the array
int pos = -1;                   // 'pos' keeps track of the last element's index (-1 means empty)

// Function to get the current number of elements in the array
int length() {
    return pos + 1;             // Total elements = last index + 1
}

// Function to insert an element at the next available position
void insert(int n) {
    if (length() == SIZE) {     // Check if array is full
        printf("The array is full\n");
    } else {
        pos++;                  // Move to next index
        a[pos] = n;             // Insert the element at that position
    }
}

// Function to search for an element 's' in the array
void search(int s) {
    int i;
    int found = 0;              // Flag to check if element is found

    for(i = 0; i <= pos; i++) { // Loop through the array
        if(a[i] == s) {         // If element matches
            printf("Found at index %d\n", i);
            found = 1;
            break;              // Stop after finding the first match
        }
    }
    if (!found) {
        printf("Element not found\n");  // If element is not found
    }
}

// Function to delete the first occurrence of element 'd'
void deletee(int d) {
    int i, j;
    int found = 0;

    for(i = 0; i <= pos; i++) {         // Loop through array
        if(a[i] == d) {                 // If element matches
            found = 1;

            // Shift elements left to overwrite the deleted one
            for(j = i; j < pos; j++) {
                a[j] = a[j + 1];
            }

            pos--;                      // Reduce total number of elements
            printf("Element %d deleted\n", d);
            break;
        }
    }

    if (!found) {
        printf("Element not found to delete\n");
    }
}

// Function to sort the array in ascending order
void sort(){
    int i, j;
    for(i = 0; i <= pos; i++){
        for(j = i + 1; j <= pos; j++){
            if(a[i] > a[j]) {           // If elements are out of order
                int temp = a[i];        // Swap them
                a[i] = a[j];		
                a[j] = temp;
            }
        }
    }
    printf("Array sorted in ascending order\n");
}

// Function to display all elements in the array
void display(){
    int i;

    if(pos == -1) {                     // Check if array is empty
        printf("Array is empty\n");
    } else {
        printf("Array contents: ");
        for(i = 0; i <= pos; i++) {     // Print all elements
            printf("%d ", a[i]);
        }
        printf("\n");
    }
}

// Function to show menu and get user choice
int menu(){
    int ch;
    printf("\n 1. Insert \n 2. Search \n 3. Delete \n 4. Sort \n 5. Display \n 6. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &ch);                   // Get choice from user
    return ch;
}

// Function to process the user’s choice using a loop and switch case
void process(){
    int ch;

    // Keep showing menu until user enters 6 (exit)
    for(ch = menu(); ch != 6; ch = menu()){
        switch(ch){
            case 1: {
                int n;
                printf("Enter the element: ");
                scanf("%d", &n);        // Read element from user
                insert(n);              // Call insert function
                break;
            }
            case 2: {
                int s;
                printf("Enter an element to search: ");
                scanf("%d", &s);        // Read element to search
                search(s);              // Call search function
                break;
            }
            case 3: {
                int d;
                printf("Enter an element to delete: ");
                scanf("%d", &d);        // Read element to delete
                deletee(d);             // Call delete function
                break;
            }
            case 4:
                sort();                 // Call sort function
                break;
            case 5:
                display();              // Call display function
                break;
            default:
                printf("Wrong choice\n"); // Handle invalid menu option
        }
    }
}

// Main function where execution begins
void main(){
    process();  // Start menu-driven program
}

