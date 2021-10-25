#include <stdio.h>
#include "enemy.h"

int main() {
  Item item = {5, 5, 0};
  Enemy enemy = InitEnemy(10, 5, 2, "Wisp", &item);
  //test InitEnemy
  PrintEnemy(enemy);
}