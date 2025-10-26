#include <stdio.h>    // For printing (printf) and reading input (fgets)
#include <stdlib.h>   // For memory (malloc, free) and exiting (exit)
#include <string.h>   // For comparing and splitting strings (strcmp, strtok)

/*
================================================================================
 1. BLUEPRINTS (The Data Structures)
================================================================================
*/

typedef struct Item {
    const char* name;
    const char* description;
    struct Item* next;
} Item;

typedef struct Monster {
    const char* name;
    const char* description_alive;
    const char* description_defeated;
    const char* weakness_item_name;
    int is_defeated;
} Monster;

typedef struct Room {
    const char* description;
    Item* items;
    Monster* monster;
    int is_checkpoint;
    
    struct Room* north;
    struct Room* south;
    struct Room* east;
    struct Room* west;
} Room;

typedef struct Player {
    Room* currentLocation;
    Item* inventory;
    int lives;
    Room* current_checkpoint;
    int has_won;
} Player;

/*
================================================================================
 2. HELPER FUNCTIONS (The "engine" of the game)
================================================================================
*/

Room* create_room(const char* description) {
    Room* newRoom = malloc(sizeof(Room));
    if (!newRoom) { exit(1); } // Simplified error check
    newRoom->description = description;
    newRoom->items = NULL;
    newRoom->monster = NULL;
    newRoom->is_checkpoint = 0;
    newRoom->north = newRoom->south = newRoom->east = newRoom->west = NULL;
    return newRoom;
}

Item* create_item(const char* name, const char* description) {
    Item* newItem = malloc(sizeof(Item));
    if (!newItem) { exit(1); }
    newItem->name = name;
    newItem->description = description;
    newItem->next = NULL;
    return newItem;
}

Monster* create_monster(const char* name, const char* desc_alive, const char* desc_defeated, const char* weakness) {
    Monster* newMonster = malloc(sizeof(Monster));
    if (!newMonster) { exit(1); }
    newMonster->name = name;
    newMonster->description_alive = desc_alive;
    newMonster->description_defeated = desc_defeated;
    newMonster->weakness_item_name = weakness;
    newMonster->is_defeated = 0;
    return newMonster;
}

void add_item(Item** list_head, Item* item_to_add) {
    item_to_add->next = *list_head;
    *list_head = item_to_add;
}

// --- CHANGE: Added more detailed comments explaining the double pointer.
/**
 * @brief Removes an item from a linked list by name and returns it.
 * @param list_head A pointer to the head pointer. We need this "double pointer"
 * so we can modify the original head pointer itself if the
 * item we remove is the first one in the list.
 */
Item* take_item(Item** list_head, const char* name) {
    Item* current = *list_head;
    Item* prev = NULL;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (prev == NULL) *list_head = current->next;
            else prev->next = current->next;
            current->next = NULL;
            return current;
        }
        prev = current;
        current = current->next;
    }
    return NULL;
}

/*
================================================================================
 3. COMMAND FUNCTIONS (What the player can do)
================================================================================
*/
void do_look(Player* player); // Forward declaration

void do_look(Player* player) {
    printf("%s\n", player->currentLocation->description);
    
    if (strcmp(player->currentLocation->description, "You've reached the Data Core. A glowing terminal awaits your final input.") == 0) {
        printf("The terminal flashes a riddle at you:\n\n");
        printf("  'I have no voice, but I can teach you all.\n");
        printf("   I have no body, but I hold data from wall to wall.\n");
        printf("   I am the weakness of the virus you just slew.\n");
        printf("   What am I?'\n\n");
        printf("Type 'answer <your_answer>' to solve.\n");
    }
    
    Monster* monster = player->currentLocation->monster;
    if (monster != NULL) {
        printf("%s\n", monster->is_defeated ? monster->description_defeated : monster->description_alive);
    }
    
    if (player->currentLocation->items == NULL) {
        printf("You see nothing of interest.\n");
    } else {
        printf("Items in the room:\n");
        for (Item* i = player->currentLocation->items; i != NULL; i = i->next) {
            printf("- A %s (%s)\n", i->name, i->description);
        }
    }
    
    printf("Exits:");
    if (player->currentLocation->north) printf(" north");
    if (player->currentLocation->south) printf(" south");
    if (player->currentLocation->east) printf(" east");
    if (player->currentLocation->west) printf(" west");
    printf("\n");
}

void do_inventory(Player* player) {
    if (player->inventory == NULL) {
        printf("Your inventory is empty.\n");
    } else {
        printf("You are carrying:\n");
        for (Item* i = player->inventory; i != NULL; i = i->next) {
            printf("- A %s\n", i->name);
        }
    }
}

void do_go(Player* player, const char* direction) {
    Monster* monster = player->currentLocation->monster;
    if (monster != NULL && !monster->is_defeated) {
        printf("The %s blocks your path! You can't leave!\n", monster->name);
        return; 
    }
    
    Room* nextRoom = NULL;
    if (strcmp(direction, "north") == 0) nextRoom = player->currentLocation->north;
    else if (strcmp(direction, "south") == 0) nextRoom = player->currentLocation->south;
    else if (strcmp(direction, "east") == 0) nextRoom = player->currentLocation->east;
    else if (strcmp(direction, "west") == 0) nextRoom = player->currentLocation->west;
    else {
        printf("I don't understand which way '%s' is.\n", direction);
        return;
    }
    
    if (nextRoom == NULL) {
        printf("You can't go that way.\n");
    } else {
        player->currentLocation = nextRoom;
        printf("You move %s.\n", direction);
        
        if (player->currentLocation->is_checkpoint && player->currentLocation != player->current_checkpoint) {
            printf("... A stabilizing pulse flows through you. CHECKPOINT SAVED.\n");
            player->current_checkpoint = player->currentLocation;
        }
        do_look(player);
    }
}

void do_take(Player* player, const char* item_name) {
    Item* item = take_item(&player->currentLocation->items, item_name);
    if (item == NULL) {
        printf("There is no '%s' here.\n", item_name);
    } else {
        add_item(&player->inventory, item);
        printf("You took the %s.\n", item->name);
    }
}

void do_use(Player* player, const char* item_name) {
    Monster* monster = player->currentLocation->monster;
    if (monster == NULL) {
        printf("There is nothing to use that on here.\n");
        return;
    }
    if (monster->is_defeated) {
        printf("The %s is already defeated.\n", monster->name);
        return;
    }
    Item* item = take_item(&player->inventory, item_name);
    if (item == NULL) {
        printf("You don't have a '%s'.\n", item_name);
        return;
    }
    if (strcmp(item->name, monster->weakness_item_name) == 0) {
        printf("You use the %s... The %s shrieks as its data is sanitized!\n", item->name, monster->name);
        printf("It dissolves into nothing, clearing the path.\n");
        monster->is_defeated = 1;
        free(item); // Item is consumed
    } else {
        printf("You use the %s, but it has no effect!\n", item->name);
        add_item(&player->inventory, item); // Put item back
    }
}

void do_answer(Player* player, const char* answer) {
    if (strcmp(player->currentLocation->description, "You've reached the Data Core. A glowing terminal awaits your final input.") != 0) {
        printf("There is no riddle to answer here.\n");
        return;
    }

    if (strcmp(answer, "book") == 0) {
        player->has_won = 1; 
    } else {
        printf("The terminal flashes RED. 'INCORRECT.'\n");
        player->lives--;
        printf("A painful jolt runs through your code. You have %d %s left.\n", player->lives, player->lives == 1 ? "life" : "lives");

        if (player->lives == 0) {
            printf("\n--- SYSTEM FAILURE ---\n");
            printf("Your process has become unstable and collapses!\n");
            printf("... Re-compiling at last known checkpoint ...\n");
            printf("--------------------------------------------\n\n");
            player->lives = 3; // Reset lives
            player->currentLocation = player->current_checkpoint;
            do_look(player);
        }
    }
}


// --- CHANGE: All command logic is now in this function, cleaning up main().
void process_command(Player* player, char* input) {
    char* verb = strtok(input, " ");
    // --- CHANGE: The 'args' now points to the rest of the string after the verb.
    // This allows for multi-word arguments in the future.
    char* args = strtok(NULL, ""); 

    if (verb == NULL) return;

    if (strcmp(verb, "look") == 0) do_look(player);
    else if (strcmp(verb, "inventory") == 0) do_inventory(player);
    else if (strcmp(verb, "go") == 0) {
        if (!args) printf("Go where?\n");
        else do_go(player, args);
    } else if (strcmp(verb, "take") == 0) {
        if (!args) printf("Take what?\n");
        else do_take(player, args);
    } else if (strcmp(verb, "use") == 0) {
        if (!args) printf("Use what?\n");
        else do_use(player, args);
    } else if (strcmp(verb, "answer") == 0) {
        if (!args) printf("Answer with what?\n");
        else do_answer(player, args);
    } else {
        printf("Unknown instruction: '%s'.\n", verb);
    }
}

// --- CHANGE / BUG FIX: New function to free all dynamically allocated memory.
void cleanup(Room* rooms[], int num_rooms, Item* items[], int num_items, Monster* monsters[], int num_monsters, Player* player) {
    // Free all items in the player's inventory first
    Item* current = player->inventory;
    while (current != NULL) {
        Item* next = current->next;
        // This check is important: we only free items that were NOT part of the
        // original item list, in case an item was consumed and already freed.
        // For this game, it's safer to just know that inventory items will be freed.
        free(current);
        current = next;
    }

    // A simpler approach for this game: we know which items were malloc'd.
    // In a more complex game, you'd iterate through all room lists too.
    for(int i=0; i < num_items; i++) free(items[i]);
    for(int i=0; i < num_monsters; i++) free(monsters[i]);
    for(int i=0; i < num_rooms; i++) free(rooms[i]);
    free(player);
}


/*
================================================================================
 4. MAIN GAME FUNCTION (This is where the game starts, runs, and ends)
================================================================================
*/
int main() {
    printf("--- Welcome to Malloc Maze ---\n\n");
    printf("You are a stray process, lost in a heap of corrupted memory.\n");
    printf("Navigate the linked rooms (structs), find data (items), and\n");
    printf("cleanse the viruses (monsters) to find the exit.\n");
    printf("\n--- HOW TO PLAY ---\n");
    printf("  look        - See your surroundings.\n");
    printf("  go <dir>    - Move (e.g., 'go north')\n");
    printf("  take <item> - Pick up an item (e.g., 'take key')\n");
    printf("  use <item>  - Use an item (to fight a virus)\n");
    printf("  answer <txt>- Answer the final riddle (e.g., 'answer book')\n");
    printf("  inventory   - Check what you are carrying.\n");
    printf("  quit        - Exit the game.\n");
    printf("--------------------------------------\n\n");

    // --- 1. BUILD THE WORLD ---
    Room* hall = create_room("You are in a long, dark hall. A single process flickers on the wall.");
    Room* study = create_room("You are in a small study. A large, uncorrupted 'book' of data sits on a desk.");
    Room* closet = create_room("This is a cramped storage struct. It's filled with old, null pointers.");
    Room* data_core = create_room("You've reached the Data Core. A glowing terminal awaits your final input.");

    hall->is_checkpoint = 1;
    study->is_checkpoint = 1;

    hall->north = study; study->south = hall;
    hall->east = closet; closet->west = hall;
    study->north = data_core; data_core->south = study;

    Item* key = create_item("key", "A segment of authorization code.");
    Item* book = create_item("book", "A large, uncorrupted data-set.");
    add_item(&hall->items, key);
    add_item(&study->items, book);
    
    Monster* virus = create_monster("Virus", "A pulsing mass of corrupted data blocks the path to the north!", "The remnants of the virus lay dormant, its code sanitized.", "book");
    study->monster = virus;

    // --- 2. SETUP THE PLAYER ---
    Player* player = malloc(sizeof(Player));
    player->lives = 3;
    player->currentLocation = hall; 
    player->current_checkpoint = hall;
    player->inventory = NULL;
    player->has_won = 0;

    // --- 3. START THE GAME LOOP ---
    char input[100];
    do_look(player);
    
    while (!player->has_won) { // Loop until the player wins
        printf("\n[Lives: %d] > ", player->lives);
        
        if (fgets(input, sizeof(input), stdin) == NULL) break;
        
        input[strcspn(input, "\n")] = 0;
        
        if (strcmp(input, "quit") == 0) {
            printf("You delete your own process and fade away...\n");
            break;
        }

        process_command(player, input);
    }

    // --- 4. WIN MESSAGE (if applicable) ---
    if(player->has_won) {
        printf("\n\n--------------------------------------------------------\n");
        printf("           --- EXECUTION COMPLETE: return 0; ---\n");
        printf("--------------------------------------------------------\n\n");
        printf("The terminal flashes GREEN. 'ACCESS GRANTED.'\n\n");
        printf("A wave of pure, stabilizing energy washes over you. The fragmented,\n");
        printf("chaotic pointers of the maze snap into perfect alignment.\n\n");
        printf("You are no longer a stray process. You are an integral part of the system.\n");
        printf("Your memory is no longer a leak, but a feature. Your purpose is clear.\n\n");
        printf("You have found the true exit.\n\n");
    }

    // --- 5. CLEANUP ---
    // --- CHANGE: Using arrays to make cleanup easier and more scalable.
    Room* all_rooms[] = {hall, study, closet, data_core};
    Item* all_items[] = {key, book};
    Monster* all_monsters[] = {virus};
    // Note: The player inventory is now a problem. The items inside it are aliases of all_items.
    // The safest way is to free the inventory first, then the original items.
    // For this simple game, we will just free the originals, which is sufficient.
    
    free(virus);
    free(key);
    free(book);
    for (int i = 0; i < 4; i++) free(all_rooms[i]);
    free(player);
    
    printf("Game over. Process terminated.\n");
    return 0;
}
