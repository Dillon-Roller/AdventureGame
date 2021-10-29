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

Character CharacterCreator(Room** map, Room** currentRoom);	// Create a new character or load an existing character
void PrintSetting();	// Output the story setting
void SaveGame(Character* character, Room* map, Room* currentRoom);	// Save the game
Character LoadGame(Room** map, Room** currentRoom);	// Load the game
Room* Menu(char cmd, Room *room, Character *character);	// The main menu and commands
void AttackCommand(Room *room, Character *character);	// Function for attacking
void UsePotionCommand(Character* character);	// Use a potion to heal the character
void PrintCommandList();	// Output a list of commands

#endif