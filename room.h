#include <stdbool.h>

#include "enemy.h"
#include "item.h"

#ifndef ROOM_H_
#define ROOM_H_

#define MAX_LEVEL 3 // Number of tree levels
#define MIN_BOSS_LEVEL 2	// Minimum level at which bosses can be placed

// The type of room determines the atmosphere and possible enemies
typedef enum type {DARK, BRIGHT, DAMP, BOSS} RoomType;

typedef struct room {
	char desc[250];	// Description of room
	RoomType type;
	int level;	// Tree level for enemy stat bonus
	//Enemy *enemy;	// Enemy guarding the room
	bool isEnemyDefeated;	// Stores whether enemy is defeated and progression is possible
	//Item *itemPtr; // Single item to add to character upon user input to interact
	struct room *up;	// Forward room
	struct room *down;	// Previous room
	struct room *left;	// Left room
	struct room *right;	// Right room
} Room;

Room* InitRoom(int level);	// Create and initialize a room
Room* CreateMap(int level, Room *r); // Recursively create linked rooms
Item* EnemyDefeated(Room *r);	// Set room bool to true to allow use of room pointers
void PrintRoom(Room *r);	// Output a room
void PrintMap(Room *r);	// Output all rooms

#endif