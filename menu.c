#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "menu.h"

Character CharacterCreator(Room** map, Room** currentRoom) {
	Character character;
	printf("Do you want to load a previous save? (y or n)\n");

	while (1) {
		char option = getchar();
		while (!isalpha(option)) { option = getchar(); } // Ensure only alphabetic characters

		if (option == 'y') {
			return LoadGame(map, currentRoom);
		}
		else if (option == 'n') {
			break;
		}
	}


	do {
		printf("Select your character type:\n\n");
		PrintCharacterTypes();

		char option = getchar();
		while (!isalpha(option)) { option = getchar(); } // Ensure only alphabetic characters

		switch (option) {
		case 'w':
			CLEAR();
			PrintSetting();
			return InitWarrior();
		case 'a':
			CLEAR();
			PrintSetting();
			return InitArcher();
		case 'z':
			CLEAR();
			PrintSetting();
			return InitWizard();
		case 'c':
			CLEAR();
			PrintSetting();
			return InitCleric();
		default:
			printf("Please select a valid character class.\n");
			break;
		}
	} while (1);
}

void PrintSetting() {
	printf(
		"You find yourself unfamiliar.\n"
		"The air is as tufts of cotton, just dotted with light from the sky above.\n"
		"The land is swampy and desolate save for but a single edifice that draws you.\n"
		"You feel the force of something pulling you in, but cannot escape its clutches.\n"
	);
}

void SaveGame(Character* character, Room* map, Room* currentRoom) {
	printf("Saving map...");
	FILE* fp = fopen("saveFile.txt", "w");
	SaveCharacter(fp, character); // Save character and items
	SaveMap(fp, map, currentRoom); // Save all rooms
	fclose(fp);
	printf("Map saved");
}

Character LoadGame(Room** map, Room** currentRoom) {
	printf("Loading save...\n");
	FILE* fp = fopen("saveFile.txt", "r");
	Character character = InitWarrior();
	if (fp != NULL) {
		char line[50];
		fgets(line, 49, fp);
		character = LoadCharacter(line);
		LoadMap(fp, map, currentRoom, NULL);
		printf("Save loaded\n\n\n");
	}
	return character;
}

Room* Menu(char cmd, Room *room, Character *character) {	
	CLEAR();

	switch(cmd) {
		case '1':	// Move to the forward room
		case '2':	// Move to the left room
		case '3':	// Move to the right room
		case '4':	// Move back to the previous room
			room = MoveToRoom(room, cmd);
			break;
		case 'f':	// Interact with a room's item
			if (room->itemPtr != NULL && !room->isItemCollected) {
				AddItemToCharacter(room->itemPtr, character);
				room->isItemCollected = true;
				printf("You have acquired a %s!\n", GetItemTypeName(room->itemPtr->type));
			}
			else if (room->isItemCollected) {
				printf("You have already taken the item.\n");
			}
			else {
				printf("There is no item here.\n");
			}
			break;
		case 'r':	// Room description
			PrintRoom(room);
			break;
		case 'e':	// Enemy description
				PrintEnemy(room->enemy);
			break;
		case 'i':	// List inventory
			if (character->itemPtr != NULL) {
				PrintItemList(character->itemPtr);
			}
			else {
				printf("Your inventory is empty.\n");
			}
			break;
		case 'c':	// Show character information
			PrintCharacter(character);
			break;
		case 'u':	// Use health potion
			UsePotionCommand(character);
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
		int dmgToEnemy = AttackEnemy(GetCharacterAttack(character), room->enemy);
		printf("You dealt %d damage to the %s.\n", dmgToEnemy, room->enemy->name);
		
		if (!IsEnemyDead(room->enemy)) {
			int dmgToChar = AttackCharacter(room->enemy->attack, character);
			printf("The %s dealt %d damage to you!\n", room->enemy->name, dmgToChar);
			if (isCharacterDead(character)) {
				CLEAR();
				printf("Your nightmare envelops you.\n");
				exit(0);
			}
			else {
				printf("You have %d health remaining.\n", GetCharacterHealth(character));
			}
		}
		else
		{
			printf("You have defeated the %s!\n", room->enemy->name);
			Item *item = EnemyDefeated(room);
			AddItemToCharacter(item, character);			
			printf("A %s has been added to your inventory\n", GetItemTypeName(item->type));
		}				
	}
}

void UsePotionCommand(Character* character) {
	if (character->numPotions > 0)
	{
		int currHealth = GetCharacterHealth(character);
		int maxHealth = GetCharacterMaxHealth(character);

		if (currHealth == maxHealth) {
			printf("Your health is already full.\n");
			return;
		}

		if (currHealth + HEALTH_POTION_VALUE > maxHealth)
		{
			character->currHealth = character->maxHealth;
		}
		else {
			character->currHealth += HEALTH_POTION_VALUE;			
		}

		character->numPotions -= 1;
		printf("You drank a health potion.\n");
		printf("Your health is now %d.\n", GetCharacterHealth(character));
		printf("You have %d %s remaining\n", character->numPotions, character->numPotions == 1 ? "potion" : "potions");
	}
	else {
		printf("You have no more health potions!\n");
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
		"'s': 	Save the game (can only save 1 game currently)\n"
		"'l': 	Load last saved game\n"
		"'q': 	Quit game\n"
		"\n"
	);
}