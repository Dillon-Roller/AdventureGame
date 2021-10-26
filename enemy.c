#include "enemy.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

Enemy* InitEnemy(int health, int attack, int defense, char* name, char* desc, Item* item) {
  Enemy* enemy = (Enemy*)malloc(sizeof(Enemy));
  enemy->health = health;
  enemy->attack = attack;
  enemy->defense = defense;
  enemy->item = item;
  strcpy(enemy->name, name);
  strcpy(enemy->desc, desc);
  return enemy;
}

void PrintEnemy(const Enemy* enemy) {
  printf("Type: %s\n", enemy->name);
  printf("Enemy description: %s\n", enemy->desc);
  printf("Health: %d\n", enemy->health);
  printf("Attack: %d\n", enemy->attack);
  printf("Defense: %d\n", enemy->defense);
}

void AttackEnemy(int damage, Enemy* enemy) {
  enemy->health -= (damage - enemy->defense);
}

Item* DropItem(const Enemy* enemy) {
  return enemy->item;
}

bool IsEnemyDead(const Enemy* enemy) {
  return enemy->health <= 0;
}

Enemy* InitGargoyle(const int level) {
  Item* item = InitItem(rand() % last_item); //generate random item
  
  return InitEnemy(3 * level, 1 * level, 1 * level, "Gargoyle", "A stone-encrusted, statuesque creature that grinds to life upon being encroached.", item);
}

Enemy* InitElemental(const int level) {
  Item* item = InitItem(rand() % last_item);

  return InitEnemy(2 * level, 2 * level, 2 * level, "Elemental", "A flaming behemoth swirling with rage.", item);
}

Enemy* InitWisp(const int level) {
  Item* item = InitItem(rand() % last_item);

  return InitEnemy(1 * level, 1 * level, 1 * level, "Wisp", "A bright cloud of sparking particles.", item);
}

Enemy* InitBoss(const int level) {
  Item* item = InitItem(rand() % last_item);

  return InitEnemy(10 * level, 5 * level, 5 * level, "Boss", "A big thing", item);
}