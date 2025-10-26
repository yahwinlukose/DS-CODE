#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for each item
struct node {
    char item[50];
    int quantity;
    float price;
    struct node* next;
};

typedef struct node node;
node* head = NULL;

// Function to insert an item
void insert_item(char* name, int qty, float price) {
    node* newNode = (node*)malloc(sizeof(node));
    strcpy(newNode->item, name);
    newNode->quantity = qty;
    newNode->price = price;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        node* t = head;
        while (t->next != NULL) {
            t = t->next;
        }
        t->next = newNode;
    }
}

// Function to delete an item by name
void delete_item(char* name) {
    node *t = head, *prev = NULL;

    if (head == NULL) {
        printf("No items in the bill.\n");
        return;
    }

    if (strcmp(head->item, name) == 0) {
        head = head->next;
        free(t);
        printf("Item '%s' removed from the bill.\n", name);
        return;
    }

    while (t != NULL && strcmp(t->item, name) != 0) {
        prev = t;
        t = t->next;
    }

    if (t == NULL) {
        printf("Item not found.\n");
        return;
    }

    prev->next = t->next;
    free(t);
    printf("Item '%s' removed.\n", name);
}

// Function to display the bill
void display_bill() {
    node* t = head;
    float total = 0.0;

    if (t == NULL) {
        printf("\nNo items to display.\n");
        return;
    }

    printf("\n-----------------------------\n");
    printf("           BILL\n");
    printf("-----------------------------\n");
    printf("%-15s %-10s %-10s\n", "Item", "Qty", "Price");

    while (t != NULL) {
        printf("%-15s %-10d %-10.2f\n", t->item, t->quantity, t->price * t->quantity);
        total += t->price * t->quantity;
        t = t->next;
    }

    printf("-----------------------------\n");
    printf("Total Amount: ?%.2f\n", total);
    printf("-----------------------------\n");
}

int main() {
    int choice, qty;
    float price;
    char name[50];

    while (1) {
        printf("\n1. Add Item\n2. Delete Item\n3. Display Bill\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter item name: ");
                scanf("%s", name);
                printf("Enter quantity: ");
                scanf("%d", &qty);
                printf("Enter price per unit: ");
                scanf("%f", &price);
                insert_item(name, qty, price);
                break;
            case 2:
                printf("Enter item name to delete: ");
                scanf("%s", name);
                delete_item(name);
                break;
            case 3:
                display_bill();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

