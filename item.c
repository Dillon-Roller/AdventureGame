#include "item.h"
#include <stdlib.h>
#include <stdio.h>

Item* InitItem(int health, int attack, int defense) {
  Item* item = (Item*)malloc(sizeof(Item));
  item->health = health;
  item->attack = attack;
  item->defense = defense;
  return item;
}

void PrintItem(const Item* item) {
  printf("Item stats:\n");
  printf("Health: %d\n", item->health);
  printf("Attack: %d\n", item->attack);
  printf("Defense: %d\n", item->defense);
}
