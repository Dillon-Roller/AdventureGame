//
// Created by Terrence Turner on 10/26/21.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "character.h"

// Creates player and sets class.
Character InitCharacter(int health, int attack, int defense) {
    Character* character = malloc(sizeof(Character));
    character->health = health;
    character->attack = attack;
    character->defense = defense;
    character->numPotions = NUM_STARTING_POTIONS;
    character->itemPtr = NULL;

    return *character;

}

Character InitWarrior(){
    Character player = InitCharacter(100, 20, 15);
    return player;
}

Character InitArcher(){
    Character player = InitCharacter(100, 18, 7);
    return player;
}

Character InitWizard(){
    Character player = InitCharacter(100, 19, 10);
    return player;
}

Character InitCleric(){
    Character player = InitCharacter(100, 15, 12);
    return player;
}

void PrintCharacter(Character* character){
    //printf("Character class: %s\n", character->class);
    printf("Health: %d\n", character->health);
    printf("Attack: %d\n", character->attack);
    printf("Defense: %d\n", character->defense);
    printf("Number of Potions: %d\n", character->numPotions);
    printf("Item: %s\n", character->itemPtr);

}
void AttackCharacter(int attack, Character* character) {
    character->health -= (attack - character->defense);

}

void AddItemToCharacter(Item *itemPtr, Character *character){
    Item *charItem = character->itemPtr;

    if (charItem == NULL) {
        charItem = itemPtr;
        return;
    }

    const char* charItemType = GetItemTypeName(charItem->type);

    while (charItem->nextItem != NULL) {
        if (strcmp(charItemType, GetItemTypeName(itemPtr->type)) == 0) {
            ItemLevelUp(charItem);
            return;
        }

        charItem = charItem->nextItem;
    }

    charItem->nextItem = itemPtr;
}


