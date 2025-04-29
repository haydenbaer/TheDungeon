#ifndef ENEMY_H
#define ENEMY_H

typedef struct
{
    char name[32];
    int health;
    int attack;
    int defense;
    int id;
} Enemy;

#endif