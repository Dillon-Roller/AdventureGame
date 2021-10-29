#include <stdlib.h>

#include "room.h"
#include "character.h"

#ifndef MENU_H_
#define MENU_H_

// Clear screen macros
#if defined __linux__ || !defined _MSC_BUILD	// Linux OS or not Visual Studio
#include <unistd.h>
#endif
#ifdef _WIN32	// Windows OS
#define CLEAR() system("cls")
#else	// Other OS
#define CLEAR() system("clear")
#endif

Character CharacterCreator(Room** map, Room** currentRoom);
void PrintSetting();
void SaveGame(Character* character, Room* map, Room* currentRoom);
Character LoadGame(Room** map, Room** currentRoom);
Room* Menu(char cmd, Room *room, Character *character);
void AttackCommand(Room *room, Character *character);
void UsePotionCommand(Character* character);
void PrintCommandList();

#endif