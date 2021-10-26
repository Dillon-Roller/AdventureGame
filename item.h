#ifndef ITEM_H_
#define ITEM_H_

typedef enum itemType {
  SWORD, SHIELD, BOW, MUSKET, ARMOR
} ItemType;

typedef struct item {
  int health;
  int attack;
  int defense;
  ItemType type;
} Item;

Item* InitItem(const ItemType type);
void PrintItem(const Item* item);

#endif