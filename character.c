//
// Created by Terrence Turner on 10/26/21.
//
#include <stdio.h>
#include <stdlib.h>
#include <printf.h>
#include "character.h"

// Creates player and sets class.
Character InitCharacter(Class class, int health, int attack, int defense) {
// Assign stats based on the given class.
    Character* tempPlayer = malloc(sizeof(Character));
    switch(class) {
        case WARRIOR:
            tempPlayer->health = 100;
            tempPlayer->attack = 20;
            tempPlayer->defense = 15;
            tempPlayer->class = WARRIOR;
            break;
        case ARCHER:
            tempPlayer->health = 100;
            tempPlayer->attack = 18;
            tempPlayer->defense = 7;
            tempPlayer->class = ARCHER;
            break;
        case WIZARD:
            tempPlayer->health = 100;
            tempPlayer->attack = 19;
            tempPlayer->defense = 10;
            tempPlayer->class = WIZARD;
            break;
        case CLERIC:
            tempPlayer->health = 100;
            tempPlayer->attack = 15;
            tempPlayer->defense = 12;
            tempPlayer->class = CLERIC;
            break;
        default:
            tempPlayer->health = 100;
            tempPlayer->attack = 10;
            tempPlayer->defense = 10;
            break;
    }

    return(tempPlayer); // Return memory address of player.

}

void PrintCharacter(Character* character){
    printf("Character class: %s\n", character->class);
    printf("Health: %d\n", character->health);
    printf("Attack: %d\n", character->attack);
    printf("Defense: %d\n", character->defense);

}
void Attack(int attack, Character* character) {
    character->health -= (attack - character->defense);

}

void PrintItems(Item *itemPtr){
    printf(itemPtr);
}

/*
Item* DropItem(const Character* character) {
    return character->item;
}
 */
