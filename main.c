#include <stdio.h>
#include <ctype.h>

#include "menu.h"
#include "room.h"
#include "character.h"

int main(void) {
	Room* map = CreateMap(1, NULL);
	Room* currentRoom = map;
	Character character = CharacterCreator(&map, &currentRoom);

	PrintRoom(currentRoom);

	char option = 0;
	
	do
	{
		printf("\nCommand your hero ('h' for command list):\n");
		option = getchar();
		while (!isalnum(option)) { option = getchar(); } // Ensure only alphabetic characters

		if (option == 'q') {	// Quit
			return 0;
		}
		
		if (option == 's') {	// Save
			CLEAR();
			SaveGame(&character, map, currentRoom);
			continue;
		}

		if (option == 'l') {	// Load
			CLEAR();
			printf("Loading a save will cause your progress to be lost.\n");
			printf("Are you sure you want to continue? (y or n)\n");

			while (1) {
				char option = getchar();
				while (!isalpha(option)) { option = getchar(); } // Ensure only alphabetic characters

				if (option == 'y') {
					character = LoadGame(map, currentRoom);
					break;
				}
				else if (option == 'n') {
					break;
				}
			}
			continue;
		}

		if (option == 'm') {
			CLEAR();
			PrintCharacterMap(map, currentRoom);
			continue;
		}

		printf("\n");

		currentRoom = Menu(option, currentRoom, &character);

	} while (1);	
}