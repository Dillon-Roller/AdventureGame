#include "item.h"
#include <stdlib.h>
#include <stdio.h>
#include "asciiArt.h"

Item* InitItem(const ItemType type) {
  Item* item = (Item*)malloc(sizeof(Item));
  if (item != NULL) {
      item->type = type;
      item->nextItem = NULL;
      item->level = 1;

      switch (item->type) {
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
      default:
          break;
      }
  }
  return item;
}

void ItemLevelUp(Item* item) {
  switch(item->type) {
    case SWORD:
      item->health += 2;
      item->attack += 2;
      break;
    case SHIELD:
      item->health += 2;
      item->defense += 2;
      break;
    case BOW:
      item->health += 2;
      item->attack += 2;
      item->defense += 2;
      break;
    case MUSKET:
      item->health += 2;
      item->attack += 2;
      item->defense += 2;
      break;
    case ARMOR:
      item->health += 2;
      item->defense += 2;
      break; 
  }
  item->level++;
}

const char* GetItemTypeName(const ItemType type) {
  switch(type) {
    case SWORD: return "Sword";
    case SHIELD: return "Shield";
    case BOW: return "Bow";
    case MUSKET: return "Musket";
    case ARMOR: return "Armor";
    case POTION: return "Potion";
    default: return "UNKNOWN_ITEM";
  }
}

void PrintItem(const Item* item) {
  printf("Item stats:\n");
  PrintItemName(item);
  printf("Health: %d\n", item->health);
  printf("Attack: %d\n", item->attack);
  printf("Defense: %d\n", item->defense);

    switch (item->type) {
        case SWORD:
            return printSword();
            break;
        case SHIELD:
            return printShield();
            break;
        case BOW:
            return printBow();
            break;
        case MUSKET:
            return printMusket();
            break;
        case ARMOR:
            return printArmor();
            break;
        case POTION:
            return printPotion();
            break;
        default:
            return "UNKNOWN_ITEM";
    }
}

void PrintItemList(Item* itemPtr) {
  while(itemPtr != NULL) {
    PrintItem(itemPtr);
    printf("\n");
    itemPtr = itemPtr->nextItem;
  }
}

void PrintItemName(const Item* item) {
  printf("%s * %d\n", GetItemTypeName(item->type), item->level);
}

