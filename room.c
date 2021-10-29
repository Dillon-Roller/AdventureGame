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
		room->isItemCollected = false;

		/// TODO: Create generate random item function
		int item = rand() % (last_item + 40);
		
		switch (item) {
			case SWORD:
				room->itemPtr = InitItem(SWORD);
				break;
			case SHIELD:
				room->itemPtr = InitItem(SHIELD);
				break;
			case BOW: 
				room->itemPtr = InitItem(BOW);
				break;
			case MUSKET: 
				room->itemPtr = InitItem(MUSKET);
				break;
			case ARMOR:
				room->itemPtr = InitItem(ARMOR);
				break;
			case POTION:		// Potion has higher chance of spawning
			case POTION+1:
			case POTION+2:
			case POTION+3:
			case POTION+4:
				room->itemPtr = InitItem(POTION);
				break;
			default:
				break;
		}
		
		if (level < MIN_BOSS_LEVEL) {
			room->type = rand() % BOSS;	// No bosses allowed under MIN_BOSS_LEVEL
		}
		else
		{
			room->type = rand() % (BOSS + 1);
		}

		SetRoomInfoByType(room, level, 0);
		/*
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
		}*/
	}
	
	return room;
}

void SetRoomInfoByType(Room* room, int level, bool isEnemyDefeated) {
	switch (room->type) {
	case DARK:
		strcpy(room->desc, "You have entered an eerily dark room.");
		if (!isEnemyDefeated) { 
			room->enemy = InitGargoyle(level); 
		}
		else {
			room->enemy = NULL;
		}
		break;
	case BRIGHT:
		strcpy(room->desc, "This room is blinding with a faint chiming.");
		if (!isEnemyDefeated) {
			room->enemy = InitWisp(level);
		}
		else {
			room->enemy = NULL;
		}
		break;
	case DAMP:
		strcpy(room->desc, "Your feet slosh about as you enter. The air is stale and the ground is wet.");
		if (!isEnemyDefeated) {
			room->enemy = InitElemental(level);
		}
		else {
			room->enemy = NULL;
		}
		break;
	case BOSS:
		strcpy(room->desc, "You enter a palatial hall with great, blood-red and golden tapestries draped over vast windows.\n"
			"The intricate detail of the woodwork is mesmerizing to gaze upon,\n"
			"but the hulking beast thrashing toward you is more intriguing.");
		if (!isEnemyDefeated) {
			room->enemy = InitBoss(level);
		}
		else {
			room->enemy = NULL;
		}
		break;
	default:
		break;
	}
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
			if (r->down != NULL) {
				r = r->down;
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
	Item* item = DropItem(r->enemy);
	r->enemy = FreeEnemy(r->enemy);
	return item;
}	

void PrintRoom(const Room *r) {
	printf("%s\n", r->desc);
	
	if (!r->isEnemyDefeated)
	{
		printf("A foe awaits: \n");
		
	}

	PrintEnemy(r->enemy);

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

void GetCharacterMapString(const Room* r, const Room* currentRoom, char* str) {
	if (r != NULL)
	{
		if (r == currentRoom) {
			strcat(str, "H");
		}
		else if (r->isEnemyDefeated) {
			strcat(str, "X");
		}
		else {
			strcat(str, "O");
		}
		GetCharacterMapString(r->up, currentRoom, str);
		GetCharacterMapString(r->left, currentRoom, str);
		GetCharacterMapString(r->right, currentRoom, str);
	}
}

void PrintCharacterMap(const Room* map, const Room* currentRoom) {
	char s[50] = "";
	GetCharacterMapString(map, currentRoom, s);

	printf(	"%c%c%c %c%c%c %c%c%c %c%c%c %c%c%c %c%c%c %c%c%c %c%c%c %c%c%c\n"
			"\\|/ \\|/ \\|/ \\|/ \\|/ \\|/ \\|/ \\|/ \\|/\n"
			" %c   %c   %c   %c   %c   %c   %c   %c   %c\n"
			"   \\ | /       \\ | /       \\ | /\n"
			"     %c           %c           %c\n"
			"        \\        |         /\n"
			"            \\    |     /\n"
			"                 %c\n",
			s[21],s[20],s[22],s[17],s[16],s[18],s[25],s[24],s[26],s[8],s[7],s[9],s[4],s[3],s[5],s[12],s[11],s[13],s[34],s[33],s[35],s[30],s[29],s[31],s[38],s[37],s[39],
			s[19],s[15],s[23],s[6],s[2],s[10],s[32],s[28],s[36],
			s[14],s[1],s[27],
			s[0]);

}

void SaveRoom(FILE* fp, const Room *r, const Room *cur) {
  int item;
  if(r->itemPtr == NULL || r->isItemCollected) {
    item = -1;
  }
  else {
    item = r->itemPtr->type;
  }
  fprintf(fp, "%d %d %d %d %d %d\n", r->type, r->level, r->isEnemyDefeated, 
    item, r->isItemCollected, r == cur ? 1 : 0);
}

void SaveMap(FILE* fp, const Room *r, const Room *cur) {
  if (r != NULL) {
    SaveRoom(fp, r, cur);
    SaveMap(fp, r->up, cur);
    SaveMap(fp, r->left, cur);
    SaveMap(fp, r->right, cur);
  }
}

Room* LoadRoom(RoomType type, int level, bool isEnemyDefeated, ItemType itemType, bool isItemCollected) {
	Room* room = (Room*)malloc(sizeof(Room));
	if (room != NULL) {
		room->type = type;
		room->level = level;
		room->isEnemyDefeated = isEnemyDefeated;
		room->itemPtr = InitItem(itemType);
		room->isItemCollected = isItemCollected;
		SetRoomInfoByType(room, level, isEnemyDefeated);
	}
	return room;
}

Room* LoadMap(FILE* fp, Room** map, Room** curr, Room* previous) {
	char line[50];
	Room* room;
	static bool flag = false;


	if (fgets(line, 49, fp)) {
		int array[6];

		// Room type
		char* token = strtok(line, " ");
		array[0] = atoi(token);

		// Room level
		token = strtok(NULL, " ");
		array[1] = atoi(token);

		// bool isEnemyDead
		token = strtok(NULL, " ");
		array[2] = atoi(token);

		// Room item
		token = strtok(NULL, " ");
		array[3] = atoi(token);

		// bool isItemCollected
		token = strtok(NULL, " ");
		array[4] = atoi(token);

		// Current room bool
		token = strtok(NULL, " ");
		array[5] = atoi(token);

		room = LoadRoom(array[0], array[1], array[2], array[3], array[4]);

		if (!flag) {
			room->down = NULL;
			*map = room;
			flag = true;
		}

		if (array[5] == 1) {	// Current room
			*curr = room;
		}

		if (array[1] > 1) {
			room->down = previous;
		}

		if (array[1] == MAX_LEVEL) {
			room->up = NULL;
			room->left = NULL;
			room->right = NULL;
			return room;
		}

		room->up = LoadMap(fp, map, curr, room);
		room->left = LoadMap(fp, map, curr, room);
		room->right = LoadMap(fp, map, curr, room);
		return room;
	}

	return NULL;
}