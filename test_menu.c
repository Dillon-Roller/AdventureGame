#include <stdio.h>
#include <ctype.h>

#include "menu.h"
#include "room.h"
#include "character.h"

void SaveGame(Character* character, Room* map, Room* currentRoom);

int main(void) {
	Room* map = CreateMap(1, NULL);
	Character character = CharacterCreator();
	Room* currentRoom = map;

	printf(
		"You find yourself unfamiliar.\n"
		"The air is as tufts of cotton, just dotted with light from the sky above.\n"
		"The land is swampy and desolate save for but a single edifice that draws you.\n"
		"You feel the force of something pulling you in, but cannot escape its clutches.\n"
	);

	PrintRoom(currentRoom);

	char option = 0;
	
	do
	{
		printf("\nCommand your hero ('h' for command list):\n");
		option = getchar();
		while (!isalnum(option)) { option = getchar(); } // Ensure only alphabetic characters

		if (option == 'q')
		{
			return 0;
		}
		
		if (option == 's') {
			SaveGame(&character, map, currentRoom);
		}
		if (option == 'm') {
			PrintCharacterMap(map);
		}
    }

		// Remove whitespace from stdin
		/*char c;
		while (isspace(c = getchar())) {}
		ungetc(c, stdin);*/

		printf("\n");

		currentRoom = Menu(option, currentRoom, &character);

	} while (1);	
}

void SaveGame(Character* character, Room* map, Room* currentRoom) {
	  printf("Saving map..");
	  FILE* fp = fopen("gameMap.txt", "w");
	  SaveCharacter(fp, &character); // Save character and items
	  SaveMap(fp, map, currentRoom); // Save all rooms
	  fclose(fp);
	  printf("Map saved");
}