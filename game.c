#include "game.h"

// PLAYER OBJECT
Player player;
// ENEMY OBJECT
Enemy enemy;

// GLOBAL VARIABLES
int run                 = 1; 
SceneID currentScene    = 0; // DEFAULT 0                             
int ifEnemy             = 0;
int currentFloor        = 1; // DEFAULT 1
int currentSpace        = 0; // DEFAULT 0
int hasLooked           = 0;
int hasHealed           = 0;
int hasWon              = 0; // Default 0
int enemiesKilled       = 0; // Default 0
int timesHealed         = 0;
int foundTreasureRoom   = 0;

int lastCheckedSpace = -1;

// CLEARS THE SCREEN BEFORE DRAWING ANYTHING
void clearScreen() 
{
    printf("\x1b[2J\x1b[H");
}

// WAITS FOR THE USER TO PRESS ENTER
void waitForEnter()
{
    printf("    PRESS ENTER TO CONTINUE...\n    ");
    getchar();
}


void printSword(Player *p)
{   
    switch (p->sword)
    {
        case 1:
            printf("Rusty Sword");
            break;
        case 2:
            printf("Iron Short Sword");
            break;
        case 3:
            printf("Knights Broadsword");
            break;
        case 4:
            printf("Excalibur Warsword");
            break;
        case 5:
            printf("Sword of Legend");
            break;
        default:
            printf("Nothing");
            break;
    }
}

void printShield(Player *p)
{
    switch (p->shield)
    {
        case 1:
            printf("Rusty Shield");
            break;
        case 2:
            printf("Iron Shield");
            break;
        case 3:
            printf("Knights Shield");
            break;
        case 4:
            printf("Dragonhide Shield");
            break;
        case 5:
            printf("Shield of Light");
            break;
        default:
            printf("Nothing");
            break;
        }
}

// GOES TO NEXT FLOOR
void nextFloor()
{
    currentSpace = 0;
    currentFloor += 1;
    foundTreasureRoom = 0;
}

// BASED ON FLOOR, RUN ENCOUNTER FUNCTION
void encounterEnemy(int floor)
{
    switch (floor)
    {
    case 1: // FLOOR 1 ENCOUNTERS
        encounterEnemyF1();
        break;
    case 2: // FLOOR 2 ENCOUNTERS
        encounterEnemyF2();
        break;
    case 3: // FLOOR 3 ENCOUNTERS
        encounterEnemyF3();
        break;
    case 4: // FLOOR 4 ENCOUNTERS
        encounterEnemyF4();
        break;
    case 5: // FLOOR 5 ENCOUNTERS
        encounterEnemyF5();
        break;
    default:
        encounterEnemyF1();
        break;
    }
}

// RANDOM ENCOUNTER FOR FLOOR 1
void encounterEnemyF1()
{
    // 0 - NO ENEMY  65%
    // 1 - RAT       20%
    // 2 - SLIME     10%
    // 3 - BAT       5%

    int num = rand() % 100;

    if (num < 20)
    {
        currentScene = RAT;
        ifEnemy = 1;
    }
    else if (num < 30)
    {
        currentScene = SLIME;
        ifEnemy = 1;
    }
    else if (num < 35)
    {
        currentScene = BAT;
        ifEnemy = 1;
    }
    else 
    {
        currentScene = NOTHING;
        ifEnemy = 0;
    }
}

void encounterEnemyF2()
{
    // 0 - NO ENEMY 65%
    // 1 - BAT      5%
    // 2 - GHOST    20%
    // 3 - IMP      10%
    int num = rand() % 100;

    if (num < 5)
    {
        currentScene = BAT;
        ifEnemy = 1;
    }
    else if (num < 25)
    {
        currentScene = GHOST;
        ifEnemy = 1;
    }
    else if (num < 35)
    {
        currentScene = IMP;
        ifEnemy = 1;
    }
    else 
    {
        currentScene = NOTHING;
        ifEnemy = 0;
    }
}

void encounterEnemyF3()
{
    // 0 - NO ENEMY 65% 
    // 1 - IMP      5%
    // 2 - SKELETON 20%
    // 3 - MUMMY    10%

    int num = rand() % 100;

    if (num < 5)
    {
        currentScene = BAT;
        ifEnemy = 1;
    }
    else if (num < 25)
    {
        currentScene = SKELETON;
        ifEnemy = 1;
    }
    else if (num < 35)
    {
        currentScene = MUMMY;
        ifEnemy = 1;
    }
    else 
    {
        currentScene = NOTHING;
        ifEnemy = 0;
    }
}

void encounterEnemyF4()
{
    // 0 - NO ENEMY 50%
    // 1 - MINOTAUR 25%
    // 2 - WENDIGOO 25%

    int num = rand() % 100;

    if (num < 25)
    {
        currentScene = MINOTAUR;
        ifEnemy = 1;
    }
    else if (num < 50)
    {
        currentScene = WENDIGOO;
        ifEnemy = 1;
    }
    else 
    {
        currentScene = NOTHING;
        ifEnemy = 0;
    }
}

void encounterEnemyF5()
{
    currentScene = DRAGON;
    ifEnemy = 1;
}

// DRAW THE USER STATS AT TOP OF SCREEN
void drawStats(const Player *p) 
{
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf(" HP: %d    ATK: %d    DF: %d    Moves: %d    Floor: %d\n", p->health, p->attack, p->defense, currentSpace, currentFloor);
    
    // PRINTS PLAYER EQUIPMENTS
    printf(" Sword: ");
    printSword(&player);
    printf("    Shield: ");
    printShield(&player);
    printf("\n");
    
    /*if (ifEnemy)
    {
        printf(" Enemy HP: %d\n", enemy.health);
    }*/
    
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
}

// DRAWS THE CURRENT SCENE THE USER IS IN
void drawScene(SceneID scene)
{
    switch (scene)
    {
        case INTRO:
            sceneIntro();
            break;
        case NOTHING:
            sceneNothing();
            break;
        case RAT:
            sceneRat();
            break;
        case SLIME:
            sceneSlime();
            break;
        case BAT:
            sceneBat();
            break;
        case GHOST:
            sceneGhost();
            break;
        case IMP:
            sceneImp();
            break;
        case SKELETON:
            sceneSkeleton();
            break;
        case MUMMY:
            sceneMummy();
            break;
        case MINOTAUR:
            sceneMinotaur();
            break;
        case WENDIGOO:
            sceneWendigoo();
            break;
        case DRAGON:
            sceneDragon();
            break;
        case STAIRS:
            sceneStairs();
            break;
    }
}

// DRAWS THE AREA FOR THE USER TO INPUT ACTIONS
void drawInput(int scene)
{
    if (ifEnemy)
    {
        int input;

        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        printf(" ACTIONS:    1. FIGHT    2. HEAL    3. INSPECT    4. COMMANDS\n");
        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");

        printf(" >> ");
        scanf("%d", &input);
        getchar();

        switch (input)
        {
        case 1:
            // ATTACK ENEMY
            fight(&enemy, &player);

            if (enemy.health <= 0 && currentScene == DRAGON)
            {
                printf("    -> You have defeated the dragon!!\n");
                waitForEnter();
                ifEnemy = 0;
                hasWon = 1;
                enemiesKilled += 1;
                run = 0;
            }
            else if (enemy.health <= 0)
            {
                printf("    -> You defeated the enemy!\n");
                waitForEnter();
                ifEnemy = 0;
                currentScene = NOTHING;
                enemiesKilled += 1;
            }
            else if (player.health <= 0)
            {
                printf("    ~ You have been slain...\n    ! GAME OVER !\n");
                waitForEnter();
                run = 0;
            }

            break;
        case 2:
            // TRY TO HEAL
            if (hasHealed)
            {
                printf("    ~ You have already tried healing!\n");
            }
            else 
            {
                heal();
            }
            waitForEnter();
            break;
        case 3:
            // SHOW ENEMY INFORMATION
            printf("    -> %s: HP: %d, ATK: %d, DF: %d\n", enemy.name, enemy.health, enemy.attack, enemy.defense);
            waitForEnter();
            break;
        case 4:
            // LIST COMMANDS
            printf("    LIST OF COMMANDS:\n");
            printf("    1. ATTACK - TRY TO ATTACK THE ENEMY\n");
            printf("    2. HEAL - TRY TO HEAL YOURSELF\n");
            printf("    3. INSPECT - CHECK OUT ENEMY INFORMATION\n");
            printf("    9. EXIT - QUITS GAME\n");
            waitForEnter();
        case 9:
            // EXIT GAME
            run = 0;
            break;
        default:
            break;
        }
    }
    else
    {
        int input;

        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        printf(" ACTIONS:    1. MOVE    2. INSPECT    3. COMMANDS\n");
        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");

        printf(" >> ");
        scanf("%d", &input);
        getchar();

        switch (input)
        {
        case 1:
            // MOVE AHEAD
            printf("    -> YOU CHOOSE TO MOVE AHEAD.\n");
            currentSpace += 1; // Increment current space
            hasLooked = 0;
            hasHealed = 0;

            checkTreasureRoom(&player, currentFloor, currentSpace, &foundTreasureRoom);
            break;
        case 2:
            inspectRoom(currentFloor);
            break;
        case 3:
            // LIST COMMANDS
            printf("    LIST OF COMMANDS:\n");
            printf("    1. MOVE - ADVANCES YOU ONE SPACE\n");
            printf("    3. INSPECT - LOOK AROUND YOU FOR INFORMATION\n");
            printf("    9. EXIT - QUITS GAME\n");
            waitForEnter();
            break;
        case 9:
            run = 0;
            break;
        default:
            break;
        }
    }
}

void inspectRoom(int currentFloor)
{
    if (currentFloor == 1)
    {
        printf("    The tunnel around you is stoney and cold...\n");
    }
    else if (currentFloor == 2)
    {
        printf("    The air is cold and wet. You hear voices whisper...\n");
    }
    else if (currentFloor == 3)
    {
        printf("    You hear footsteps and groans echo ahead...\n");
    }
    else if (currentFloor == 4)
    {
        printf("    Stomps echo from ahead in the tunnel...\n");
    }
    else if (currentFloor == 5)
    {

    }

    waitForEnter();
}

void fight(Enemy *e, Player *p) {
    // PLAYER ATTACK
    if (rand() % 100 < HIT_CHANCE) {
        int dmg = p->attack - e->defense;
        if (dmg < 1) dmg = 1; // ALWAYS AT LEAST 1 DAMAGE
        printf("    -> You hit the enemy for %d damage!\n", dmg);
        e->health -= dmg;
    } else {
        printf("    ~ Your attack misses!\n");
    }

    // ENEMY COUNTERATTACK - IF ALIVE
    if (e->health > 0) {
        if (rand() % 100 < HIT_CHANCE) {
            int dmg = e->attack - p->defense;
            if (dmg < 0) dmg = 0; // NEVER HEAL YOU WITH HIT
            printf("    -> Enemy hits you for %d damage!\n", dmg);
            p->health -= dmg;
        } else {
            printf("    ~ Enemy attack misses!\n");
        }
    }

    waitForEnter();
}


void setupEnemyStats()
{
    switch (currentScene)
    {
        case NOTHING:
            enemy.health = 0;
            enemy.attack = 0;
            enemy.defense = 0;
            enemy.id = 0;
            break;
        case RAT:
            enemy.health = 12;
            enemy.attack = 4;
            enemy.defense = 0;
            enemy.id = 1;
            strcpy(enemy.name, "RAT");
            break;
        case SLIME:
            enemy.health = 14;
            enemy.attack = 5;
            enemy.defense = 1;
            enemy.id = 2;
            strcpy(enemy.name, "SLIME");
            break;
        case BAT:
            enemy.health = 10;
            enemy.attack = 4;
            enemy.defense = 0;
            enemy.id = 3;
            strcpy(enemy.name, "BAT");
            break;
        case GHOST:
            enemy.health = 20;
            enemy.attack = 6;
            enemy.defense = 2;
            enemy.id = 4;
            strcpy(enemy.name, "GHOST");
            break;
        case IMP:
            enemy.health = 18;
            enemy.attack = 6;
            enemy.defense = 1;
            enemy.id = 5;
            strcpy(enemy.name, "IMP");
            break;
        case SKELETON:
            enemy.health = 28;
            enemy.attack = 8;
            enemy.defense = 4;
            enemy.id = 6;
            strcpy(enemy.name, "SKELETON");
            break;
        case MUMMY:
            enemy.health = 32;
            enemy.attack = 8;
            enemy.defense = 6;
            enemy.id = 7;
            strcpy(enemy.name, "MUMMY");
            break;
        case MINOTAUR:
            enemy.health = 40;
            enemy.attack = 12;
            enemy.defense = 8;
            enemy.id = 8;
            strcpy(enemy.name, "MINOTAUR");
            break;
        case WENDIGOO:
            enemy.health = 45;
            enemy.attack = 14;
            enemy.defense = 8;
            enemy.id = 9;
            strcpy(enemy.name, "WENDIGOO");
            break;
        case DRAGON:
            enemy.health = 120;
            enemy.attack = 20;
            enemy.defense = 10;
            enemy.id = 10;
            strcpy(enemy.name, "DRAGON");
            break;
        default:
        break;
    }
}

int askToEquip() {
    char input;

    printf("    Would you like to equip? [Y / N]\n    >> ");
    fflush(stdout);

    // the leading space in "%c" tells scanf to skip any whitespace
    scanf(" %c", &input);

    if (input=='Y' || input=='y') {
        printf("    -> Equipped!\n");
        return 'Y';
    } else {
        printf("    ~ Not equipped!\n");
        return 'N';
    }
}

void heal() {
    if (hasHealed) {
        printf("    ~ You've already healed this fight!\n");
    }
    else if (rand() % 100 < HEAL_CHANCE) {
        int amt = 10 + rand() % 16;       // heal between 10 and 25 HP
        player.health += amt;
        if (player.health > MAX_HEALTH)
            player.health = MAX_HEALTH;
        printf("    -> You heal %d HP!\n", amt);
        timesHealed++;
    } 
    else {
        printf("    ~ Your heal failed!\n");
    }

    hasHealed = 1;
}


// MAIN GAME LOOP FUNCTION
void game() 
{
    // BASE PLAYER ATTACK AND DEFENSE WITH NOTHING EQUIPPED
                            // DEFAULTS
    player.health   = MAX_HEALTH;  // 100
    player.attack   = 3;    // 3
    player.defense  = 2;    // 2
    player.sword    = 0;    // 0
    player.shield   = 0;    // 0

    clearScreen();
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    sceneIntro();
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");

    waitForEnter();
    getchar();

    // ADVANCE TO THE NEXT SCENE
    currentScene = NOTHING;

    // WHILE GAME SHOULD RUN -> LOOP
    while(run) 
    {        
        // CLEAR SCREEN BEGINNING OF EACH LOOP
        clearScreen();

        if (currentSpace == 10 && currentFloor == 1 && ifEnemy == 0)
        {
            currentScene = STAIRS;
        }

        if (currentSpace == 11 && currentFloor == 1)
        {
            // GO TO SECOND FLOOR
            nextFloor();
        }

        if (currentSpace == 15 && currentFloor == 2 && ifEnemy == 0)
        {
            currentScene = STAIRS;
        }

        if (currentSpace == 16 && currentFloor == 2)
        {
            // GO TO THIRD FLOOR
            nextFloor();
        }
        if (currentSpace == 16 && currentFloor == 3)
        {
            // GO TO FOURTH FLOOR
            nextFloor();
        }

        if (currentSpace == 15 && currentFloor == 3 && ifEnemy == 0)
        {
            currentScene = STAIRS;
        }

        if (currentSpace == 16 && currentFloor == 4)
        {
            // GO TO FIFTH FLOOR
            nextFloor();
        }

        if (currentSpace == 15 && currentFloor == 4 && ifEnemy == 0)
        {
            currentScene = STAIRS;
        }

        // IF NOT IN BEGINNING SPACE - CHECK ENCOUNTERS
        if (currentSpace != lastCheckedSpace && currentSpace >= 1)
        {
            encounterEnemy(currentFloor);
            lastCheckedSpace = currentSpace;

            if (ifEnemy)
            {
                setupEnemyStats();
            }
        }

        // DRAW ALL SCREEN ELEMENTS
        drawStats(&player);
        drawScene(currentScene);
        drawInput(currentScene);

        

    }

    // GAME BEATEN ENDING
    if (hasWon)
    {
        clearScreen();
        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        printf("\n    After deafeating the dragon, you see a pile of riches.\n");
        printf("    Gold coins, shining jewels, and a gleaming\n");
        printf("    golden necklace.\n");
        printf("\n    You pick it up and put it on. You feel a power surge\n");
        printf("    through you. At long last, you have overcome The Dungeon.\n");
        printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        printf("\n    Player Stats:\n");
        printf("     HP: %d    ATK: %d    DF: %d\n", player.health, player.attack, player.defense);
        printf("     Enemies Killed: %d    Times Healed: %d\n", enemiesKilled, timesHealed);
        waitForEnter();
    }
}