#include "item.h"

#ifndef ENEMY_H_
#define ENEMY_H_

typedef struct enemy {
  int health;
  int attack;
  int defense;
  char desc[250];
  Item item;
} Enemy;

Enemy InitEnemy(int health, int attack, int defense, char* desc, Item* item);

#endif