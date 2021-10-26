#include <stdio.h>
#include <ctype.h>

#include "menu.h"

Character CharacterCreator() {
	printf("Select your character type:\n\n");
	//PrintCharacterTypes();
	char option = getchar();
	while (!isalpha(option)) { option = getchar(); } // Ensure only alphabetic characters
}

Room* Menu(char cmd, Room *room, Character *character) {	
	switch(cmd) {
		case '1':	// Move to the forward room
		case '2':	// Move to the left room
		case '3':	// Move to the right room
		case '4':	// Move back to the previous room
			room = MoveToRoom(room, cmd);
			break;
		case 'f':	// Interact with a room's item
			if (room->itemPtr != NULL) {
				AddItemToCharacter(room->itemPtr, character);
				printf("You have acquired a %s!\n", GetItemTypeName(room->itemPtr->type));
			}
			else {
				printf("There is no item here\n");
			}
			break;
		case 'r':	// Room description
			PrintRoom(room);
			break;
		case 'e':	// Enemy description
			PrintEnemy(room->enemy);
			break;
		case 'i':	// List inventory
			PrintItemList(character->itemPtr);
			break;
		case 'c':	// Show character information
			PrintCharacter(character);
			break;
		case 'u':	// Use health potion
			break;
		case 'a':	// Attack enemy
			AttackCommand(room, character);
			break;
		case 'h':
			PrintCommandList();
			break;
		default:
			break;		
	}

	return room;
}

void AttackCommand(Room *room, Character *character) {
	if (room->isEnemyDefeated) {
		printf("You have already vanquished this enemy!\n");
	}
	else {
		AttackEnemy(character->attack, room->enemy);
		printf("You dealt %d damage to the %s.\n", character->attack, room->enemy->name);
		
		if (!IsEnemyDead(room->enemy)) {
			AttackCharacter(room->enemy->attack, character);
			printf("The %s dealt %d damage to you!\n", room->enemy->name, room->enemy->attack);
			printf("You have %d health remaining.\n", character->health);
		}
		else
		{
			Item *item = EnemyDefeated(room);
			AddItemToCharacter(item, character);
			printf("You have defeated the %s!\n", room->enemy->name);
			printf("A %s has been added to your inventory\n", GetItemTypeName(item->type));
		}				
	}
}

void PrintCommandList() {
	printf(
		"Command List:\n\n"
		"'1':	Move to the forward room\n"
		"'2':	Move to the left room\n"
		"'3':	Move to the right room\n"
		"'4':	Move back to the previous room\n"
		"'f':	Interact with a room's item\n"
		"'r':	Show room description\n"
		"'e':	Show enemy description\n"
		"'i':	List inventory\n"
		"'c':	Show character information\n"
		"'u':	Use health potion\n"
		"'a':	Attack enemy\n"
		"'h':	Show command list\n"
		"'q': 	Quit game\n"
		"\n"
	);
}