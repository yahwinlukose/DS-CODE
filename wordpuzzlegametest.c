#include <stdio.h>    // For printing (printf) and reading input (fgets)
#include <stdlib.h>   // For memory (malloc, free) and exiting (exit)
#include <string.h>   // For comparing and splitting strings (strcmp, strtok)

/*
================================================================================
 1. BLUEPRINTS (The Data Structures)
================================================================================
*/

// Blueprint for an item (a node in a linked list)
typedef struct Item {
    const char* name;          // Name used in commands, e.g., "key"
    const char* description;   // Text displayed when you look at it
    struct Item* next;         // Pointer to the next item in the list
} Item;

// Blueprint for a room (a node in the world graph)
typedef struct Room {
    const char* description;   // The text shown when the player enters
    Item* items;               // The HEAD of a linked list of items in this room
    
    // Pointers to adjacent rooms. NULL means no exit in that direction.
    struct Room* north;
    struct Room* south;
    struct Room* east;
    struct Room* west;
} Room;

// Blueprint for the player
typedef struct Player {
    Room* currentLocation;     // A pointer to the room the player is in
    Item* inventory;           // The HEAD of a linked list of items carried
} Player;


/*
================================================================================
 2. HELPER FUNCTIONS (The "engine" of the game)
================================================================================
*/

/**
 * @brief Allocates memory for a new room and initializes it.
 * @param description The text to show when the player enters.
 * @return A pointer to the newly created room.
 */
Room* create_room(const char* description) {
    Room* newRoom = malloc(sizeof(Room));
    if (newRoom == NULL) {
        printf("Error: Not enough memory to create a room!\n");
        exit(1);
    }
    newRoom->description = description;
    newRoom->items = NULL;
    newRoom->north = NULL;
    newRoom->south = NULL;
    newRoom->east = NULL;
    newRoom->west = NULL;
    return newRoom;
}

/**
 * @brief Allocates memory for a new item.
 * @param name The name used in 'take' commands (e.g., "key").
 * @param description The text shown when you 'look' at it.
 * @return A pointer to the newly created item.
 */
Item* create_item(const char* name, const char* description) {
    Item* newItem = malloc(sizeof(Item));
    if (newItem == NULL) {
        printf("Error: Not enough memory to create an item!\n");
        exit(1);
    }
    newItem->name = name;
    newItem->description = description;
    newItem->next = NULL;
    return newItem;
}

/**
 * @brief Adds an item to a linked list (room or inventory).
 * This function adds the new item to the *front* of the list.
 */
void add_item(Item** list_head, Item* item_to_add) {
    item_to_add->next = *list_head; // Set new item's 'next' to the current first item
    *list_head = item_to_add;      // Update the list head to be the new item
}

/**
 * @brief Removes an item from a linked list (by name) and returns it.
 * This is the most complex data structure logic here.
 * @param list_head A pointer to the head pointer (a double pointer).
 * @param name The name of the item to take.
 * @return A pointer to the removed item, or NULL if not found.
 */
Item* take_item(Item** list_head, const char* name) {
    Item* current = *list_head;
    Item* prev = NULL;

    // Loop through the list to find the item
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            // Found it! Now we "unlink" it.
            if (prev == NULL) {
                // It was the first item in the list.
                *list_head = current->next;
            } else {
                // It was in the middle or end.
                prev->next = current->next;
            }
            current->next = NULL; // Detach the item from the list
            return current;
        }
        // Didn't find it yet, move to the next item
        prev = current;
        current = current->next;
    }
    return NULL; // Item not found
}

/*
================================================================================
 3. COMMAND FUNCTIONS (What the player can do)
================================================================================
*/

/**
 * @brief Prints the description, items, and exits of the current room.
 */
void do_look(Player* player) {
    // 1. Print room description
    printf("%s\n", player->currentLocation->description);
    
    // 2. Print items in the room
    if (player->currentLocation->items == NULL) {
        printf("You see nothing of interest.\n");
    } else {
        printf("Items in the room:\n");
        Item* current_item = player->currentLocation->items;
        while (current_item != NULL) {
            printf("- A %s (%s)\n", current_item->name, current_item->description);
            current_item = current_item->next; // Move to the next item
        }
    }
    
    // 3. Print available exits
    printf("Exits:");
    if (player->currentLocation->north) printf(" north");
    if (player->currentLocation->south) printf(" south");
    if (player->currentLocation->east) printf(" east");
    if (player->currentLocation->west) printf(" west");
    printf("\n");
}

/**
 * @brief Prints the player's inventory.
 */
void do_inventory(Player* player) {
    if (player->inventory == NULL) {
        printf("Your inventory is empty.\n");
    } else {
        printf("You are carrying:\n");
        Item* current_item = player->inventory;
        while (current_item != NULL) {
            printf("- A %s\n", current_item->name);
            current_item = current_item->next;
        }
    }
}

/**
 * @brief Moves the player to a different room.
 */
void do_go(Player* player, const char* direction) {
    Room* nextRoom = NULL;

    if (strcmp(direction, "north") == 0) {
        nextRoom = player->currentLocation->north;
    } else if (strcmp(direction, "south") == 0) {
        nextRoom = player->currentLocation->south;
    } else if (strcmp(direction, "east") == 0) {
        nextRoom = player->currentLocation->east;
    } else if (strcmp(direction, "west") == 0) {
        nextRoom = player->currentLocation->west;
    } else {
        printf("I don't understand which way '%s' is.\n", direction);
        return;
    }
    
    if (nextRoom == NULL) {
        printf("You can't go that way.\n");
    } else {
        player->currentLocation = nextRoom;
        printf("You move %s.\n", direction);
        do_look(player); // Automatically look at the new room
    }
}

/**
 * @brief Takes an item from the room and adds it to the player's inventory.
 */
void do_take(Player* player, const char* item_name) {
    // 1. Try to remove the item from the room's list.
    Item* item = take_item(&player->currentLocation->items, item_name);
    
    // 2. Check if the item was found.
    if (item == NULL) {
        printf("There is no '%s' here.\n", item_name);
    } else {
        // 3. Add the item to the player's inventory list.
        add_item(&player->inventory, item);
        printf("You took the %s.\n", item->name);
    }
}


/*
================================================================================
 4. MAIN GAME FUNCTION (This is where the game starts, runs, and ends)
================================================================================
*/
int main() {
    // --- 0. PRINT TUTORIAL ---
    printf("--- Welcome to Malloc Maze ---\n\n");
    printf("You awaken in a world built from pure data.\n");
    printf("Navigate the linked rooms, find items, and discover the exit.\n");
    printf("\n--- HOW TO PLAY ---\n");
    printf("Type commands to interact with the world.\n");
    printf("  look        - See your surroundings.\n");
    printf("  go <dir>    - Move in a direction (e.g., 'go north')\n");
    printf("  take <item> - Pick up an item (e.g., 'take key')\n");
    printf("  inventory   - Check what you are carrying.\n");
    printf("  quit        - Exit the game.\n");
    printf("--------------------------------------\n\n");

    // --- 1. BUILD THE WORLD ---
    Room* hall = create_room("You are in a long, dark hall. A single torch flickers on the wall.");
    Room* study = create_room("You are in a small study. A large, dusty book sits on a desk.");
    Room* closet = create_room("This is a cramped storage closet. It's filled with cobwebs.");

    // Link the rooms
    hall->north = study;
    study->south = hall;
    hall->east = closet;
    closet->west = hall;

    // Create items
    Item* key = create_item("key", "A small, rusty brass key.");
    Item* book = create_item("book", "A heavy, leather-bound tome.");
    
    // Place items in rooms
    add_item(&hall->items, key);
    add_item(&study->items, book);

    // --- 2. SETUP THE PLAYER ---
    Player* player = malloc(sizeof(Player));
    player->currentLocation = hall; // Set starting room
    player->inventory = NULL;       // Start with empty inventory

    // --- 3. START THE GAME LOOP ---
    char input[100]; // A buffer to hold the player's command.
    do_look(player); // Look at the starting room
    
    while (1) {
        printf("\n> ");
        
        if (fgets(input, sizeof(input), stdin) == NULL) {
            printf("Error reading input.\n");
            break;
        }
        
        input[strcspn(input, "\n")] = 0; // Remove the newline
        
        // --- 4. PARSE THE INPUT ---
        char* verb = strtok(input, " ");
        char* noun = strtok(NULL, " ");

        // --- 5. EXECUTE THE COMMAND ---
        if (verb == NULL) {
            continue; 
        }

        if (strcmp(verb, "quit") == 0) {
            printf("You give up and accept your fate...\n");
            break;
        } else if (strcmp(verb, "look") == 0) {
            do_look(player);
        } else if (strcmp(verb, "inventory") == 0) {
            do_inventory(player);
        } else if (strcmp(verb, "go") == 0) {
            if (noun == NULL) {
                printf("Go where?\n");
            } else {
                do_go(player, noun);
            }
        } else if (strcmp(verb, "take") == 0) {
            if (noun == NULL) {
                printf("Take what?\n");
            } else {
                do_take(player, noun);
            }
        } else {
            printf("I don't understand how to '%s'.\n", verb);
        }
    }

    // --- 6. CLEANUP ---
    // Free all memory we allocated.
    // This is C's "garbage collection" - we have to do it manually!
    free(hall);
    free(study);
    free(closet);
    free(key);
    free(book);
    free(player); 
    // Note: We don't need to free items in lists because they are
    // the same 'key' and 'book' pointers, which we already freed.
    
    printf("Game over.\n");
    return 0; // Exit successfully
}
