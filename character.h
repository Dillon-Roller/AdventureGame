//
// Created by Terrence Turner on 10/26/21.
//

#ifndef ADVENTUREGAME_CHARACTER_H
#define ADVENTUREGAME_CHARACTER_H
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
    int health;
    int attack;
    int defense;
    int numPotions
    Item *itemPtr;	// Linked list
} Character;

//functions
Character InitCharacter(int health, int attack, int defense, int numPotions, Item* item);
Character InitWarrior();
Character InitArcher();
Character InitWizard();
Character InitCleric();
void PrintItems(Item *itemPtr);
void PrintCharacter(Character* character);
void AttackCharacter(int attack, Character* character);


#endif //ADVENTUREGAME_CHARACTER_H
