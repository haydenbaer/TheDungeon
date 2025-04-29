#ifndef GAME_H
#define GAME_H

#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <time.h>
#include "player.h"
#include "enemy.h"
#include "scene.h"
#include "item.h"

// CHECK IF GAME SHOULD RUN T/F
extern int run;
// TRACK IF THERE IS AN ENEMY ON THE SCREEN
extern int ifEnemy;
// VARIABLE TO TRACK THE CURRENT SCENE
extern SceneID currentScene;
// TRACKS THE CURRENT FLOOR THE PLAYER IS ON
extern int currentFloor;
// TRACKS THE CURRENT SPACE THE USER IS ON
extern int currentSpace;

extern Player player;

// I/O FUNCTIONS
void clearScreen();
void waitForEnter();

void printSword(Player *p);
void printShield(Player *p);

// FUCNTIONS TO ENCOUNTER ENEMIES
void encounterEnemy(int floor);
void encounterEnemyF1();
void encounterEnemyF2();
void encounterEnemyF3();
void encounterEnemyF4();
void encounterEnemyF5();

// DRAWING TO SCREEN
void drawStats(const Player *p);
void drawScene(SceneID scene);
void drawInput(int scene);

// MAIN GAME FUNCTIONS
void game(); 
void fight(Enemy *e, Player *p);
void setupEnemyStats();
void look(Player *p);
int askToEquip();
void heal();

#endif