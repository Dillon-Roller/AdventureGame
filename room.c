#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "room.h"

Room* InitRoom(int level) {
	Room *room = (Room*)malloc(sizeof(Room));
	
	if (room != NULL) {
		if (level == 0) {
			time_t t;
			srand((unsigned) time(&t));
		}
		
		room->level = level;
		
		if (level < MIN_BOSS_LEVEL) {
			room->type = rand() % BOSS;	// No bosses allowed under MIN_BOSS_LEVEL
		}
		else
		{
			room->type = rand() % BOSS + 1;
		}
		switch(room->type) {
			case DARK:
				strcpy(room->desc, "You have entered an eerily dark room.");
				//room.enemy = CreateGargoyle
				//room->itemPtr = NULL;
				break;
			case BRIGHT:
				strcpy(room->desc, "This room is blinding with a faint chiming.");
				//CreateWisp
				//room.itemPtr = CreateItem(...);
				break;
			case DAMP:
				strcpy(room->desc, "Your feet slosh about as you enter. The air is stale and the ground is wet.");
				break;
			case BOSS:
				strcpy(room->desc, "Run");
				//CreateBoss
				break;
			default:
				break;
		}
	}
	
	return room;
}

Room* CreateMap(int level, Room *r) { // Recursively create rooms
	Room *room = InitRoom(level);
	
	if (level == MAX_LEVEL)
	{
		room->up = NULL;
		room->left = NULL;
		room->right = NULL;		
	}
	else
	{	
		room->up = CreateMap(level+1, room);
		room->left = CreateMap(level+1, room);
		room->right = CreateMap(level+1, room);
	}
	if (level > 0) {
		room->down = r;
	}
	else {
		room->down = NULL;
	}
	
	return room;
}

void PrintRoom(Room *r) {
	printf("%s\n", r->desc);
	printf("%d\n", r->type);
	printf("Level %d\n", r->level);
	printf("\n");
}

void PrintMap(Room *r) {
	if (r != NULL)
	{
		PrintRoom(r);
		PrintMap(r->up);
		PrintMap(r->left);
		PrintMap(r->right);
	}
}