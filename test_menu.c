#include <stdio.h>
#include <ctype.h>

#include "menu.h"
#include "room.h"
#include "character.h"

int main(void) {
	Room* map = CreateMap(0, NULL);
	Character character = InitWarrior();
	Room* currentRoom = map;
	char option = 0;
	
	do
	{
		printf("Command your hero ('h' for command list):\n");
		option = getchar();
		while (!isalpha(option)) { option = getchar(); } // Ensure only alphabetic characters

		if (option == 'q')
		{
			return 0;
		}

		// Remove whitespace from stdin
		/*char c;
		while (isspace(c = getchar())) {}
		ungetc(c, stdin);*/

		currentRoom = Menu(option, currentRoom, &character);

	} while (1);	
}