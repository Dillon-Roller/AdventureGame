//
// Created by Terrence Turner on 10/26/21.
//

#include <stdbool.h>

#include "item.h"

#ifndef ADVENTUREGAME_CHARACTER_H
#define ADVENTUREGAME_CHARACTER_H

#define NUM_STARTING_POTIONS 3
#define HEALTH_POTION_VALUE 30

//character classes enum
typedef enum ClassEnum {
    WIZARD,
    WARRIOR,
    CLERIC,
    ARCHER
} Class;


//Character stuct
typedef struct character_struct {
    Class class;
    int currHealth;
	int maxHealth;
    int attack;
    int defense;
    int numPotions;

    int itemHealth; // Amount of health added by items
    int itemAttack; // Amount of attack added by items
    int itemDefense;    // Amount of defense added by items
    Item *itemPtr;	// Linked list
} Character;

//functions
Character InitCharacter(int health, int attack, int defense, Class class);
Character InitWarrior();
Character InitArcher();
Character InitWizard();
Character InitCleric();
void PrintCharacter(Character* character);
void PrintCharacterTypes();
int AttackCharacter(int damage, Character* character);
const char* GetCharacterType(const Class class);
void AddItemToCharacter(Item *itemPtr, Character *character);
int GetCharacterHealth(Character* character);
int GetCharacterMaxHealth(Character* character);
int GetCharacterAttack(Character* character);
int GetCharacterDefense(Character* character);
void AddItemBonuses(Character* character);
bool isCharacterDead(Character* character);


#endif //ADVENTUREGAME_CHARACTER_H
