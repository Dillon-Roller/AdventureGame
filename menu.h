#include "room.h"
#include "character.h"

#ifndef MENU_H_
#define MENU_H_

// Clear screen macros
#ifndef _MSC_BUILD	// If not using Visual Studio
#include <unistd.h>
#endif
// linux macro
#ifdef _WIN32	// Windows OS
#define CLEAR() system("cls")
#else	// Other OS
#define CLEAR() system("clear")
#endif

Character CharacterCreator();
Room* Menu(char cmd, Room *room, Character *character);
void AttackCommand(Room *room, Character *character);
void UsePotionCommand(Character* character);
void PrintCommandList();

#endif