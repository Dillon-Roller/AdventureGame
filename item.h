#ifndef ITEM_H_
#define ITEM_H_

typedef enum itemType {
  SWORD, SHIELD, BOW, MUSKET, ARMOR,
  last_item //used to signal end of enum for generating random enum
} ItemType;

typedef struct item {
  int health;
  int attack;
  int defense;
  ItemType type;
  struct item* nextItem;
} Item;

Item* InitItem(const ItemType type);
void PrintItem(const Item* item);
const char* GetItemTypeName(const ItemType type);

#endif