#include <stdio.h>
#include "enemy.h"

int main() {
  Item* item = InitItem(SWORD);
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
  PrintItem(item);
  printf("\n");

  //test isDead
  printf("Enemy after being attacked for 10 more damage with defense 2\n");
  AttackEnemy(10, enemy);
  printf("Enemy is %s\n", isDead(enemy) ? "dead" : "alive");
}