//
// Created by Terrence Turner on 10/26/21.
//

#include "item.h"

#ifndef ADVENTUREGAME_CHARACTER_H
#define ADVENTUREGAME_CHARACTER_H

#define NUM_STARTING_POTIONS 3
#define HEALTH_POTION_VALUE 30

//character classes enum
/*typedef enum ClassEnum {
    WIZARD,
    WARRIOR,
    CLERIC,
    ARCHER
} Class;
 */

//Character stuct
typedef struct character_struct {
    int currHealth;
	int maxHealth;
    int attack;
    int defense;
    int numPotions;
    Item *itemPtr;	// Linked list
} Character;

//functions
Character InitCharacter(int health, int attack, int defense);
Character InitWarrior();
Character InitArcher();
Character InitWizard();
Character InitCleric();
void PrintCharacter(Character* character);
void AttackCharacter(int attack, Character* character);
void AddItemToCharacter(Item *itemPtr, Character *character);


#endif //ADVENTUREGAME_CHARACTER_H
