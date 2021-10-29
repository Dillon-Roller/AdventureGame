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

//Character creation functions
Character InitCharacter(int health, int attack, int defense, Class class);
Character InitWarrior();
Character InitArcher();
Character InitWizard();
Character InitCleric();

void PrintCharacter(Character* character);  // Print character info
void PrintCharacterTypes(); // Print starting info for all characters
int AttackCharacter(int damage, Character* character);  // Damage a character's health
const char* GetCharacterType(const Class class);    // Get the class type for a character
void AddItemToCharacter(Item *itemPtr, Character *character);   // Add an item to a character
int GetCharacterHealth(Character* character);   // Return current health value
int GetCharacterMaxHealth(Character* character);    // Return maximum health value
int GetCharacterAttack(Character* character);   // Return attack value
int GetCharacterDefense(Character* character);  // Return defense value
void AddItemBonuses(Character* character);  // Calculate item bonus values for a character
bool isCharacterDead(Character* character); // Return if a character is dead
void SaveCharacter(FILE* fp, Character* character); // Save the character
void SaveCharacterItems(FILE* fp, Character* character);    // Save the character's items
Character LoadCharacter(char* characterString); // Load a character and items

#endif //ADVENTUREGAME_CHARACTER_H
