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
		
		room->isEnemyDefeated = false;		
		room->level = level;
		room->itemPtr = NULL;
		
		if (level < MIN_BOSS_LEVEL) {
			room->type = rand() % BOSS;	// No bosses allowed under MIN_BOSS_LEVEL
		}
		else
		{
			room->type = rand() % (BOSS + 1);
		}
		switch(room->type) {
			case DARK:
				strcpy(room->desc, "You have entered an eerily dark room.");
				room->enemy = InitGargoyle(level);
				break;
			case BRIGHT:
				strcpy(room->desc, "This room is blinding with a faint chiming.");
				room->enemy = InitWisp(level);
				break;
			case DAMP:
				strcpy(room->desc, "Your feet slosh about as you enter. The air is stale and the ground is wet.");
				room->enemy = InitElemental(level);
				break;
			case BOSS:
				strcpy(room->desc,  "You enter a palatial hall with great, blood-red and golden tapestries draped over vast windows.\n"
									"The intricate detail of the woodwork is mesmerizing to gaze upon,\n"
									"but the hulking beast thrashing toward you is more intriguing.");
				room->enemy = InitBoss(level);
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

Room* MoveToRoom(Room *r, char option) {
	switch(option) {
	case '1':	// Move to the forward room
			if (r->isEnemyDefeated && r->up != NULL) {
				r = r->up;
				PrintRoom(r);
			}
			else if (r->isEnemyDefeated && r->up == NULL) {
				printf("The path is blocked.\n");
				printf("Find another way.\n");
			}
			else {
				printf("You must defeat the enemy to move on.\n");
			}
			break;
		case '2':	// Move to the left room
			if (r->isEnemyDefeated && r->left != NULL) {
				r = r->left;
				PrintRoom(r);
			}
			else if (r->isEnemyDefeated && r->left == NULL) {
				printf("The path is blocked.\n");
				printf("Find another way.\n");
			}
			else {
				printf("You must defeat the enemy to move on.\n");
			}
			break;
		case '3':	// Move to the right room
			if (r->isEnemyDefeated && r->right != NULL) {
				r = r->right;
				PrintRoom(r);
			}
			else if (r->isEnemyDefeated && r->right == NULL) {
				printf("The path is blocked.\n");
				printf("Find another way.\n");
			}
			else {
				printf("You must defeat the enemy to move on.\n");
			}
			break;
		case '4':	// Move back to the previous room
			r = r->down;
			if (r != NULL) {
				printf("You return to the previous room:\n");
				PrintRoom(r);
			}
			else {
				static bool flag = false;
				if (!flag) {
					printf("Your story is only beginning\n");
					flag = true;
				}
				else {
					printf("You are at the beginning\n");
				}
			}
			break;
		default:
			break;
	}
	
	return r;
}

Item* EnemyDefeated(Room *r) {
	r->isEnemyDefeated = true;
	return DropItem(r->enemy);
}	

void PrintRoom(const Room *r) {
	printf("%s\n", r->desc);
	
	if (!r->isEnemyDefeated)
	{
		printf("A foe awaits: \n");
		PrintEnemy(r->enemy);
	}
	else {
		printf("The foe is sprawled atop shimmering mess\n");
	}
	
	printf("You are %d %s deep into this nightmare.", r->level, r->level == 1 ? "level" : "levels");
	printf("\n");
}

void PrintMap(const Room *r) {
	if (r != NULL)
	{
		PrintRoom(r);
		PrintMap(r->up);
		PrintMap(r->left);
		PrintMap(r->right);
	}
}