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
    if (character != NULL) {
        character->currHealth = character->maxHealth = health;
        character->attack = attack;
        character->defense = defense;
        character->numPotions = NUM_STARTING_POTIONS;
        character->itemPtr = NULL;
    }
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
    printf("Health: %d/%d\n", character->currHealth, character->maxHealth);
    printf("Attack: %d\n", character->attack);
    printf("Defense: %d\n", character->defense);
    printf("Number of Potions: %d\n", character->numPotions);
    printf("Item: %s\n", character->itemPtr);

}

void PrintCharacterTypes(){
    //Warrior
    char warrior[] = "Warrior (w)";
    char warriorHealth[] = "Health: 100";
    char warriorAttack[] = "Attack: 20";
    char warriorDefense[] = "Defense: 15";
    char warriorPotions[] = "Potions: 1";

    //Archer
    char archer[] = "Archer (a)";
    char archerHealth[] = "Health: 100";
    char archerAttack[] = "Attack: 18";
    char archerDefense[] = "Defense: 7";
    char archerPotions[] = "Potions: 1";

    //Wizard
    char wizard[] = "Wizard (z)";
    char wizardHealth[] = "Health: 100";
    char wizardAttack[] = "Attack: 19";
    char wizardDefense[] = "Defense: 10";
    char wizardPotions[] = "Potions: 1";

    //Cleric
    char cleric[] = "Cleric (c)";
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

int AttackCharacter(int damage, Character* character) {
    int resultDmg = 0;

    if (damage > character->defense) {
        resultDmg = (damage - character->defense);
        character->currHealth -= resultDmg;
    }

    return resultDmg;
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


bool isCharacterDead(Character* character) {
    if (character->currHealth <= 0){
        return true;
    }

    return false;
}