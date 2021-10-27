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

void PrintCharacterType(){
    //Warrior
    char warrior[] = "Warrior";
    char warriorHealth[] = "Health: 100";
    char warriorAttack[] = "Attack: 20";
    char warriorDefense[] = "Defense: 15";
    char warriorPotions[] = "Potions: 1";

    //Archer
    char archer[] = "Archer";
    char archerHealth[] = "Health: 100";
    char archerAttack[] = "Attack: 18";
    char archerDefense[] = "Defense: 7";
    char archerPotions[] = "Potions: 1";

    //Wizard
    char wizard[] = "Wizard";
    char wizardHealth[] = "Health: 100";
    char wizardAttack[] = "Attack: 19";
    char wizardDefense[] = "Defense: 10";
    char wizardPotions[] = "Potions: 1";

    //Cleric
    char cleric[] = "Cleric";
    char clericHealth[] = "Health: 100";
    char clericAttack[] = "Attack: 15";
    char clericDefense[] = "Defense: 12";
    char clericPotions[] = "Potions: 1";

    printf("%-20s %-20s %-20s %-20s\n", warrior, archer, wizard, cleric);
    printf("%-20s %-20s %-20s %-20s\n", warriorHealth, archerHealth, wizardHealth, clericHealth);
    printf("%-20s %-20s %-20s %-20s\n", warriorAttack, archerAttack, wizardAttack, clericAttack);
    printf("%-20s %-20s %-20s %-20s\n", warriorDefense, archerDefense, wizardDefense, clericDefense);
    printf("%-20s %-20s %-20s %-20s\n", warriorPotions, archerPotions, wizardPotions, clericPotions);

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


