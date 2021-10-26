#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "enemy.h"

int main() {
  srand(time(NULL));

  Item* item = InitItem(SHIELD);
  Enemy* enemy = InitEnemy(10, 5, 2, "Wisp", item);

  //test InitEnemy
  printf("Test InitEnemy:\n");
  PrintEnemy(enemy);
  printf("\n");

  //test AttackEnemy
  printf("Enemy after being attacked for 10 damage with 2 defense\n");
  AttackEnemy(10, enemy);
  PrintEnemy(enemy);
  printf("\n");

  //test DropItem
  printf("Enemy dropped item:\n");
  Item* droppedItem = DropItem(enemy);
  PrintItem(droppedItem);
  printf("\n");

  //test isDead
  printf("Enemy after being attacked for 10 more damage with defense 2\n");
  AttackEnemy(10, enemy);
  printf("Enemy is %s\n\n", IsEnemyDead(enemy) ? "dead" : "alive");

  //test initGargoyle
  printf("Spawning Level 1 Gargoyle:\n");
  Enemy* gargoyle = InitGargoyle(1);
  PrintEnemy(gargoyle);
  PrintItem(DropItem(gargoyle));
  printf("\n");

  //level item up
  printf("Leveling Gargoyle item up\n");
  ItemLevelUp(gargoyle->item);
  PrintItem(gargoyle->item);

}