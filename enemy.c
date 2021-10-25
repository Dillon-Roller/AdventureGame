#include "enemy.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

Enemy* InitEnemy(int health, int attack, int defense, char* desc, Item* item) {
  Enemy* enemy = (Enemy*)malloc(sizeof(Enemy));
  enemy->health = health;
  enemy->attack = attack;
  enemy->defense = defense;
  enemy->item = item;
  strcpy(enemy->desc, desc);
  return enemy;
}

void PrintEnemy(const Enemy* enemy) {
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