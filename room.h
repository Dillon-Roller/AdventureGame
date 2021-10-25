#ifndef ROOM_H_
#define ROOM_H_

#define MAX_LEVEL 3
#define MIN_BOSS_LEVEL 2

typedef enum type {DARK, BRIGHT, DAMP, BOSS} RoomType;

typedef struct room {
	char desc[250];
	RoomType type;
	int level;	// tree level for enemy stat bonus
	//Enemy *enemy;
	//Item *itemPtr; // Single item to add to character upon user input to interact
	struct room *up;
	struct room *down;
	struct room *left;
	struct room *right;
} Room;

Room* InitRoom(int level);
Room* CreateMap(int level, Room *r); // Recursively create rooms
void PrintRoom(Room *r);
void PrintMap(Room *r);

#endif