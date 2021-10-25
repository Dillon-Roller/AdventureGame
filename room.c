#include <stdio.h>
#include <stdlib.h>

#include "room.h"

Room* InitRoom(int level) {
	Room *room = (Room*)malloc(sizeof(Room));
	
	if (room != NULL) {
		if (level < MIN_BOSS_LEVEL) {
			room->type = rand() % (BOSS - 1);	// No bosses allowed under MIN_BOSS_LEVEL
		}
		else
		{
			room->type = rand() % BOSS;
		}
		switch(room->type) {
			case DARK:
				//room.enemy = CreateGargoyle
				//room->itemPtr = NULL;
				break;
			case BRIGHT:
				//CreateWisp
				//room.itemPtr = CreateItem(...);
				break;
			case BOSS:
				//CreateBoss
				break;
			default:
				break;
		}
	}
	
	return room;
}

Room* CreateMap(int level, Room *r) { // Recursively create rooms
	/*if (level == MAX_LEVEL)
	{
		…
		return...
	}

	Room *room = InitRoom(level);
	
	room->up = CreateMap(level+1, room);
	room->left = CreateMap(level+1, room);
	room->right = CreateMap(level+1, room);

	if (level > 0) {
		room->down = r;
	}
	else {
		room->down = NULL;
	}*/
	return r;
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
	}
	
	PrintMap(r->up);
	PrintMap(r->left);
	PrintMap(r->right);
}