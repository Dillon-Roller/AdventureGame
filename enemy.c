#include "enemy.h"
#include <string.h>

Enemy InitEnemy(int health, int attack, int defense, char* desc, Item* item) {
  Enemy enemy;
  enemy.health = health;
  enemy.attack = attack;
  enemy.defense = defense;
  strcpy(enemy.desc, desc);
  return enemy;
}