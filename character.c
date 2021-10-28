//
// Created by Terrence Turner on 10/26/21.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "character.h"

// Creates player
Character InitCharacter(int health, int attack, int defense, Class class) {
    Character character;
    character.class = class;
    character.currHealth = character.maxHealth = health;
    character.attack = attack;
    character.defense = defense;
    character.numPotions = NUM_STARTING_POTIONS;

    // Item stats
    character.itemHealth = 0;
    character.itemAttack = 0;
    character.itemDefense = 0;
    character.itemPtr = NULL;
    return character;

}

Character InitWarrior(){
    Character player = InitCharacter(100, 20, 15, WARRIOR);
    return player;
}

Character InitArcher(){
    Character player = InitCharacter(100, 18, 7, ARCHER);
    return player;
}

Character InitWizard(){
    Character player = InitCharacter(100, 19, 10, WIZARD);
    return player;
}

Character InitCleric(){
    Character player = InitCharacter(100, 15, 12, CLERIC);
    return player;
}

void PrintCharacter(Character* character){
    printf("Class: %s\n", GetCharacterType(character->class));
    printf("Health: %d(%d+%d) / %d(%d+%d)\n", GetCharacterHealth(character), character->currHealth, character->itemHealth, GetCharacterMaxHealth(character), character->maxHealth, character->itemHealth);
    printf("Attack: %d(%d+%d)\n", GetCharacterAttack(character), character->attack, character->itemAttack);
    printf("Defense: %d(%d+%d)\n", GetCharacterDefense(character), character->defense, character->itemDefense);
    printf("Number of Potions: %d\n", character->numPotions);
    PrintItemList(character->itemPtr);
}

void PrintCharacterTypes(){
    //Warrior
    char warrior[] = "Warrior (w)";
    char warriorHealth[] = "Health: 100";
    char warriorAttack[] = "Attack: 20";
    char warriorDefense[] = "Defense: 15";
    char warriorPotions[] = "Potions: xx";
    sprintf(warriorPotions, "Potions: %d", NUM_STARTING_POTIONS);

    //Archer
    char archer[] = "Archer (a)";
    char archerHealth[] = "Health: 100";
    char archerAttack[] = "Attack: 18";
    char archerDefense[] = "Defense: 7";
    char archerPotions[] = "Potions: xx";
    sprintf(archerPotions, "Potions: %d", NUM_STARTING_POTIONS);

    //Wizard
    char wizard[] = "Wizard (z)";
    char wizardHealth[] = "Health: 100";
    char wizardAttack[] = "Attack: 19";
    char wizardDefense[] = "Defense: 10";
    char wizardPotions[] = "Potions: xx";
    sprintf(wizardPotions, "Potions: %d", NUM_STARTING_POTIONS);

    //Cleric
    char cleric[] = "Cleric (c)";
    char clericHealth[] = "Health: 100";
    char clericAttack[] = "Attack: 15";
    char clericDefense[] = "Defense: 12";
    char clericPotions[] = "Potions: xx";
    sprintf(clericPotions, "Potions: %d", NUM_STARTING_POTIONS);

    printf("%-20s %-20s %-20s %-20s\n", warrior, archer, wizard, cleric);
    printf("%-20s %-20s %-20s %-20s\n", warriorHealth, archerHealth, wizardHealth, clericHealth);
    printf("%-20s %-20s %-20s %-20s\n", warriorAttack, archerAttack, wizardAttack, clericAttack);
    printf("%-20s %-20s %-20s %-20s\n", warriorDefense, archerDefense, wizardDefense, clericDefense);
    printf("%-20s %-20s %-20s %-20s\n", warriorPotions, archerPotions, wizardPotions, clericPotions);

}

const char* GetCharacterType(const Class class) {
    switch(class) {
        case WARRIOR: return "Warrior";
        case ARCHER: return "Archer";
        case WIZARD: return "Wizard";
        case CLERIC: return "Cleric";
        default: return "UNKNOWN_CLASS";
    }
}

int AttackCharacter(int damage, Character* character) {
    int resultDmg = 0;

    if (damage > GetCharacterDefense(character)) {
        resultDmg = (damage - GetCharacterDefense(character));
        character->currHealth -= resultDmg;
    }
    return resultDmg;
}

void AddItemToCharacter(Item* itemPtr, Character* character){
    Item* charItem = character->itemPtr;

    if (itemPtr->type == POTION) {
        character->numPotions++;
        return;
    }

    if (charItem == NULL) {
        character->itemPtr = itemPtr;
        AddItemBonuses(character);
        return;
    }

    const char* newItemType = GetItemTypeName(itemPtr->type);
    Item* tempItem = charItem;


    while (charItem != NULL) {
        if (strcmp(newItemType, GetItemTypeName(charItem->type)) == 0) {
            ItemLevelUp(charItem);
            AddItemBonuses(character);
            return;
        }

        tempItem = charItem;
        charItem = charItem->nextItem;
    }

    tempItem->nextItem = itemPtr;
    AddItemBonuses(character);
}

int GetCharacterHealth(Character* character) {
    return character->currHealth + character->itemHealth;
}

int GetCharacterMaxHealth(Character* character) {
    return character->maxHealth + character->itemHealth;
}

int GetCharacterAttack(Character* character) {
    return character->attack + character->itemAttack;
}

int GetCharacterDefense(Character* character) {
    return character->defense + character->itemDefense;
}

void AddItemBonuses(Character* character) {
    Item* charItem = character->itemPtr;
    int health = 0;
    int attack = 0;
    int defense = 0;


    while (charItem != NULL) {
        health += charItem->health;
        attack += charItem->attack;
        defense += charItem->defense;
        charItem = charItem->nextItem;
    }

    character->itemHealth = health;
    character->itemAttack = attack;
    character->itemDefense = defense;
}


bool isCharacterDead(Character* character) {
    if (GetCharacterHealth(character) <= 0){
        return true;
    }

    return false;
}
void SaveCharacter(FILE* fp, Character* character) {
  fprintf(fp, "%d ", character->class);
  SaveCharacterItems(fp, character);
}

void SaveCharacterItems(FILE* fp, Character* character) {
  Item* item = character->itemPtr;
  while(item != NULL) {
    fprintf(fp, "%d %d ", item->type, item->level);
    item = item->nextItem;
  }
  fprintf(fp, "\n");
}

Character LoadCharacter(char* characterString) {
	Character character;
	int class;
	char *token;
	
	token = strtok(characterString, " ");
	class = atoi(token);
	
	switch (class) {
		case WIZARD:
			character = InitWizard();
			break;
		case WARRIOR:
			character = InitWarrior();
			break;
		case ARCHER:
			character = InitArcher();
			break;
		case CLERIC:
			character = InitCleric();
			break;
        default:
            character = InitWarrior();
            break;
	}

	Item *item;
	int level;
	
	token = strtok(NULL, " ");
	
	while (token != NULL && strcmp(token, "\n") != 0) {
		item = InitItem(atoi(token));
		token = strtok(NULL, " ");
		level = atoi(token);
		
		for (int i = 0; i < level - 1; i++) {
			ItemLevelUp(item);
		}
		
		AddItemToCharacter(item, &character);
		token = strtok(NULL, " ");
	}
	
	return character;
}

