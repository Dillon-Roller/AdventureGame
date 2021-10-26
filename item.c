#include "item.h"
#include <stdlib.h>
#include <stdio.h>

Item* InitItem(const ItemType type) {
  Item* item = (Item*)malloc(sizeof(Item));
  item->type = type;
  item->nextItem = NULL;

  switch(item->type) {
    case SWORD:
      item->health = 5;
      item->attack = 10;
      item->defense = 0;
      break;
    case SHIELD:
      item->health = 5;
      item->attack = 0;
      item->defense = 10;
      break;
    case BOW:
      item->health = 5;
      item->attack = 5;
      item->defense = 5;
      break;
    case MUSKET:
      item->health = 5;
      item->attack = 15;
      item->defense = 5;
      break;
    case ARMOR:
      item->health = 10;
      item->attack = 0;
      item->defense = 10;
      break;
  }
  return item;
}

const char* GetItemTypeName(const ItemType type) {
  switch(type) {
    case SWORD: return "Sword";
    case SHIELD: return "Shield";
    case BOW: return "Bow";
    case MUSKET: return "Musket";
    case ARMOR: return "Armor";
  }
}

void PrintItem(const Item* item) {
  printf("Item stats:\n");
  printf("Type: %s\n", GetItemTypeName(item->type));
  printf("Health: %d\n", item->health);
  printf("Attack: %d\n", item->attack);
  printf("Defense: %d\n", item->defense);
}


