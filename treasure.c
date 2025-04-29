#include "treasure.h"

void checkTreasureRoom(Player *p, int currentFloor, int currentSpace, int *foundTreasureRoom)
{
    int chance = 0;

    if (currentSpace < 10)
    {
        switch (currentFloor)
        {
            case 1:
                chance = 10;
                break;
            case 2:
                chance = 12;
                break;
            case 3:
                chance = 15;
                break;
            case 4:
                chance = 18;
                break;
        }
    }
    else {
        switch (currentFloor)
        {
            case 1:
                chance = 80;
                break;
            case 2:
                chance = 25;
                break;
            case 3:
                chance = 25;
                break;
            case 4:
                chance = 25;
                break;
        }
    }
    

    if (rand() % 100 < chance)
    {
        printf("    -> You find a chest with treasures!\n");
        waitForEnter();

        int reward = rand() % 2; // O = SWORD, 1 = SHIELD

        // SWORD
        if (reward == 0)
        {
            if (currentFloor == 1)
            {
                p->attack = RUSTY_SWORD_ATK;
                p->sword = RUSTY_SWORD;
                printf("    -> You found a Rusty Sword!\n");
            }
            if (currentFloor == 2)
            {
                p->attack = KNIGHTS_BROADSWORD_ATK;
                p->sword = KNIGHTS_BROADSWORD;
                printf("    -> You found a Knight's Broadsword!\n");
            }
            if (currentFloor == 3)
            {
                p->attack = EXCALIBUR_WARSWORD_ATK;
                p->sword = EXCALIBUR_WARSWORD;
                printf("    -> You found the Excalibur Warsword!\n");
            }
            if (currentFloor == 4)
            {
                p->attack = SWORD_OF_LEGEND_ATK;
                p->sword = SWORD_OF_LEGEND;
                printf("    -> You found the legendary Sword of Legend!!\n");
            }
        }
        else if (reward == 1)
        {
            if (currentFloor == 1)
            {
                p->defense = RUSTY_SHIELD_DF;
                p->shield = RUSTY_SHIELD;
                printf("    -> You found a Rusty Shield!\n");
            }
            if (currentFloor == 2)
            {
                p->defense = KNIGHTS_SHIELD_DF;
                p->shield = KNIGHTS_SHIELD;
                printf("    -> You found a Knight's Shield!\n");
            }
            if (currentFloor == 3)
            {
                p->defense = DRAGONHIDE_SHIELD_DF;
                p->shield = DRAGONHIDE_SHIELD;
                printf("    -> You found a Dragonhide Shield!\n");
            }
            if (currentFloor == 4)
            {
                p->defense = SHIELD_OF_LIGHT_DF;
                p->shield = SHIELD_OF_LIGHT;
                printf("    -> You found the legendary Shield of Light!!\n");
            }
        }
    
        waitForEnter();
    }
}