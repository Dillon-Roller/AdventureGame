#ifndef ITEM_H_
#define ITEM_H_

typedef struct item {
  int health;
  int attack;
  int defense;
} Item;

Item* InitItem(int health, int attack, int defense);
void PrintItem(const Item* item);

#endif