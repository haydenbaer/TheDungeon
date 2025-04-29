#ifndef TREASURE_H
#define TREASURE_H

#include <stdio.h>
#include "item.h"
#include "player.h"
#include "enemy.h"
#include "game.h"

void checkTreasureRoom(Player *p, int currentFloor, int currentSpace, int *foundTreasureRoom);

#endif