#include <stdbool.h>

#include "enemy.h"
#include "item.h"

#ifndef ROOM_H_
#define ROOM_H_

#define MAX_LEVEL 4 // Number of tree levels
#define MIN_BOSS_LEVEL 3	// Minimum level at which bosses can be placed

// The type of room determines the atmosphere and possible enemies
typedef enum type {DARK, BRIGHT, DAMP, BOSS} RoomType;

typedef struct room {
	char desc[250];	// Description of room
	RoomType type;
	int level;	// Tree level for enemy stat bonus
	Enemy *enemy;	// Enemy guarding the room
	bool isEnemyDefeated;	// Stores whether enemy is defeated and progression is possible
	Item *itemPtr; // Single item to add to character upon user input to interact
	bool isItemCollected;	// Stores whether item has been collected by user
	struct room *up;	// Forward room
	struct room *down;	// Previous room
	struct room *left;	// Left room
	struct room *right;	// Right room
} Room;

Room* InitRoom(const int level);	// Create and initialize a room
void SetRoomInfoByType(Room* room, int level, bool isEnemyDefeated);	// Set specific information based on RoomType
Room* CreateMap(const int level, Room *r); // Recursively create linked rooms
Room* MoveToRoom(Room *r, const char option);	// Move to an adjacent room
Item* EnemyDefeated(Room *r);	// Set room bool to true to allow use of room pointers
void PrintRoom(const Room *r);	// Output a room
void PrintMap(const Room *r);	// Output all rooms
void GetCharacterMapString(const Room* r, const Room* currentRoom, char* str);	// Return a string representation of the map
void PrintCharacterMap(const Room* map, const Room* currentRoom); // Output all rooms that the character has seen
void SaveMap(FILE* fp, const Room *r, const Room *cur); // Save all rooms to file
void SaveRoom(FILE* fp, const Room *r, const Room *cur); // Save room to file
Room* LoadRoom(RoomType type, int level, bool isEnemyDefeated, ItemType itemType, bool isItemCollected);	// Load a room from file
Room* LoadMap(FILE* fp, Room** map, Room** curr, Room* previous);	// Load the map from file

#endif