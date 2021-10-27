#include "item.h"
#include <stdbool.h>

#ifndef ENEMY_H_
#define ENEMY_H_

/* struct holding information about an enemy */
typedef struct enemy {
  int health;
  int attack;
  int defense;
  char name[50];
  char desc[250];
  Item* item; //all enemies drop an item upon being defeated
} Enemy;

//Returns a new enemy with given stats
Enemy* InitEnemy(int health, int attack, int defense, char* name, char* desc, Item* item);
//Print information about enemy
void PrintEnemy(const Enemy* enemy);
//Deal damage to enemy and return amount
int AttackEnemy(int damage, Enemy* enemy);
//Return the item held by enemy
Item* DropItem(const Enemy* emeny);
//Returns true if enemy health is <= 0 else false
bool IsEnemyDead(const Enemy* enemy);

//Init enemies with various stats
Enemy* InitGargoyle(const int level);
Enemy* InitElemental(const int level);
Enemy* InitWisp(const int level);
Enemy* InitBoss(const int level);

#endif