#include "enemy.h"
#include "asciiArt.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

Enemy* InitEnemy(int health, int attack, int defense, char* name, char* desc, Item* item) {
  Enemy* enemy = (Enemy*)malloc(sizeof(Enemy));
  if (enemy != NULL)
  {
	  enemy->health = health;
	  enemy->attack = attack;
	  enemy->defense = defense;
	  enemy->item = item;
	  strcpy(enemy->name, name);
	  strcpy(enemy->desc, desc);
  }
  return enemy;
}

void PrintEnemy(const Enemy* enemy) {
	if (enemy != NULL) {
		printf("Type: %s\n", enemy->name);
		printf("Enemy description: %s\n", enemy->desc);
		printf("Health: %d\n", enemy->health);
		printf("Attack: %d\n", enemy->attack);
		printf("Defense: %d\n", enemy->defense);
    
    if(strcmp(enemy->name, "Gargoyle") == 0) {
      printGargoyle();
    }
    else if(strcmp(enemy->name, "Elemental") == 0) {
      printElemental();
    }
    else if(strcmp(enemy->name, "Wisp") == 0) {
      printWisp();
    }
    else {
      printBoss();
    }
	}
	else {
		printf("The foe is sprawled atop shimmering mess\n");
	}
}

int AttackEnemy(int damage, Enemy* enemy) {
	int resultDmg = 0;

	if (damage > enemy->defense) {
		resultDmg = (damage - enemy->defense);
		enemy->health -= resultDmg;
	}

	return resultDmg;
}

Item* DropItem(const Enemy* enemy) {
  return enemy->item;
}

bool IsEnemyDead(const Enemy* enemy) {
  return enemy->health <= 0;
}

Enemy* InitGargoyle(const int level) {
  Item* item = InitItem(rand() % last_item); //generate random item
  
  return InitEnemy(25 + 10 * level, 15 + 7 * level, 13 + 5 * level, "Gargoyle", "A stone-encrusted, statuesque creature that grinds to life upon being encroached.", item);
}

Enemy* InitElemental(const int level) {
  Item* item = InitItem(rand() % last_item);

  return InitEnemy(15 + 10 * level, 10 + 10 * level, 10 + 2 * level, "Elemental", "An ebbing behemoth swirling with rage.", item);
}

Enemy* InitWisp(const int level) {
  Item* item = InitItem(rand() % last_item);

  return InitEnemy(20 + 5 * level, 12 + 5 * level, 7 + 2 * level, "Wisp", "A bright cloud of sparking particles.", item);
}

Enemy* InitBoss(const int level) {
  Item* item = InitItem(rand() % last_item);

  return InitEnemy(50 * level, 35 * level, 20 * level, "Boss", "A big thing", item);
}