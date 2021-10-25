#include "enemy.h"
#include <string.h>
#include <stdio.h>

Enemy InitEnemy(int health, int attack, int defense, char* desc, Item* item) {
  Enemy enemy;
  enemy.health = health;
  enemy.attack = attack;
  enemy.defense = defense;
  strcpy(enemy.desc, desc);
  return enemy;
}

void PrintEnemy(Enemy enemy) {
  printf("Enemy description: %s\n", enemy.desc);
  printf("Health: %d\n", enemy.health);
  printf("Attack: %d\n", enemy.attack);
  printf("Defense: %d\n", enemy.defense);
}