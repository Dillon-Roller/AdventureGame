//
// Created by Terrence Turner on 10/26/21.
//

#ifndef ADVENTUREGAME_CHARACTER_H
#define ADVENTUREGAME_CHARACTER_H
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
    int health;
    int attack;
    int defense;
    Item *itemPtr;	// Linked list
} Character;

//functions
Character InitCharacter(Class class, int health, int attack, int defense);
void PrintItems(Item *itemPtr);
void PrintCharacter(Character* character);
void Attack(int attack, Character* character);
//Item* DropItem(const Character* character);

#endif //ADVENTUREGAME_CHARACTER_H
