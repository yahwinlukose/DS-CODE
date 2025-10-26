#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Item{
	const char* name;
	const char* description;
	struct Item* next;
}item;
typedef struct Room{
	const char* description;
	item* items;
	struct Room* north;
	struct Room* south;
	struct Room* west;
	struct Room* east;
}room;
typedef struct Player{
	room* currentLocation;
	item* inventory;		
}player;
room* create_room(const char* description){
	room* new_room=malloc(sizeof(room));
	if(new_room==NULL){
		printf("memory allocation failed\n");
		exit(1);
	}
	new_room->description=description'
	new_room->items=NULL;
	new_room->north=NULL;
	new_room->south=NULL;
	new_room->east=NULL;
	new_room->west=NULL;
	return new_room;'
}
item* create_new_item(const char* name,const char* description){
	item* newitem=malloc(sizeof(item));
	if(newitem==NULL){
		printf("memory allocation failed\n");
		exit(1);
	}
	newitem->name=name;
	newitem->description=description;
	newitem->next=NULL;
	return newitem;
}
void do_look(player* player){
	printf("%s\n",player->currentLocation->description);
	if(player->currentLocation->items==NULL){
		printf("you see nothing of interest\n");
	}else{
		printf("you see:\n");
		//todo
	}
}
void do_go(player* player,const char* direction){
	room* next_room=NULL;
	if(strcmp(direction,"north")==0){
		next_room=player->currentLocation->north;
	}else if(strcmp(direction,"south")==0){
		next_room=player->currentLocation->south;
	}else if(strcmp(direction,"east")==0){
		next_room=player->currentLocation->east;
	}else if(strcmp(direction,"west")==0){
		next_room=player->currentLocation->west;
	}else{
		printf("I dont understand which way '%s' is. \n",direction);
		return;
	}
	if(next_room==NULL){
		printf("you can't go that way\n'");
	}else{
		player->currentLocation=next_room;
		printf("you move %s.\n",direction);
		do_look(player);
	}
}
