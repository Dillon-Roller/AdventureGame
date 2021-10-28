#ifndef ITEM_H_
#define ITEM_H_

/* enum holding different types of items */
typedef enum itemType {
  SWORD, SHIELD, BOW, MUSKET, ARMOR, POTION,
  last_item //used to signal end of enum for generating random enum
} ItemType;

/* struct representing an item */
typedef struct item {
  int health;
  int attack;
  int defense;
  int level;
  ItemType type;
  struct item* nextItem;
} Item;

Item* InitItem(const ItemType type); //Initializes an item
void PrintItem(const Item* item); //Print information about an item
const char* GetItemTypeName(const ItemType type); //Returns a string based off the item type
void ItemLevelUp(Item* item); //Increase stats of item to next level
void PrintItemName(const Item* item); //Print item name and level
void PrintItemList(Item* itemPtr); //Print item list

#endif