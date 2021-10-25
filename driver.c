#include <stdlib.h>

#include "room.h"

int main(void) {
	Room start = {"something about the room", BRIGHT, 0};
	Room r1 = {"Room 1", DAMP, 1};
	Room r2 = {"Room 2", DARK, 2};
	Room r3 = {"Room 3", BOSS, 3};
	
	start.up = &r1;
	start.down = NULL;
	start.right = NULL;
	start.left = NULL;
	
	r1.up = &r2;
	r1.down = &start;
	r1.right = NULL;
	r1.left = NULL;
	
	r2.up = &r3;
	r2.down = &r1;
	r2.right = NULL;
	r2.left = NULL;
	
	r3.up = NULL;
	r3.down = &r2;
	r3.right = NULL;
	r3.left = NULL;
	
	PrintMap(&start);
	return 0;
}