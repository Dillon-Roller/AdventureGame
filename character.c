//
// Created by Terrence Turner on 10/26/21.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <printf.h>
#include "character.h"
#include "item.h"

// Creates player and sets class.
Character InitCharacter(int health, int attack, int defense, int numPotions, Item* item) {
    Character* character = malloc(sizeof(Character));
    character->health = health;
    character->attack = attack;
    character->defense = defense;
    character->numPotions = numPotions;
    character->itemPtr = item;

    return *character;

}

Character InitWarrior(){
    Character player = InitCharacter(100, 20, 15, 1);
    return player;
}

Character InitArcher(){
    Character player = InitCharacter(100, 18, 7, 1);
    return player;
}

Character InitWizard(){
    Character player = InitCharacter(100, 19, 10, 1);
    return player;
}

Character InitCleric(){
    Character player = InitCharacter(100, 15, 12, 1);
    return player;
}

void PrintCharacter(Character* character){
    printf("Character class: %s\n", character->class);
    printf("Health: %d\n", character->health);
    printf("Attack: %d\n", character->attack);
    printf("Defense: %d\n", character->defense);
    printf("Number of Potions: %d\n", character->numPotions);
    PrintItemList(character->itemPtr);

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

    while (charItem->next != NULL) {
        if (strcmp(charItem->name, itemPtr->name) == 0) {
            ItemLevelUp(charItem);
            return;
        }

        charItem = charItem->next;
    }

    charItem->next = itemPtr;
}


