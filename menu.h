#include "room.h"
#include "character.h"

#ifndef MENU_H_
#define MENU_H_

Character CharacterCreator();
Room* Menu(char cmd, Room *room, Character *character);
void AttackCommand(Room *room, Character *character);
void UsePotionCommand(Character* character);
void PrintCommandList();

#endif