#include <stdio.h>
#include "enemy.h"

int main() {
  Item* item = InitItem(5, 5, 0);
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
}