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
    //printf("    >> ");
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {} // FLUSH NEWLINE FROM BUFFER
    getchar(); // WAITS FOR THE ENTER KEY
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
    
    if (ifEnemy)
    {
        printf(" Enemy HP: %d\n", enemy.health);
    }
    
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
    }
}

// DRAWS THE AREA FOR THE USER TO INPUT ACTIONS
void drawInput(int scene)
{
    if (scene == 0) {
        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        waitForEnter();

        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");

        // ADVANCE TO THE NEXT SCENE
        currentScene = 1;
    }
    else
    {
        if (ifEnemy)
        {
            int input;

            printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
            printf(" ACTIONS:    1. FIGHT    2. HEAL    3. LOOK    4. COMMANDS\n");
            printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");

            printf(" >> ");
            scanf("%d", &input);
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
                // LOOK AROUND
                if (hasLooked)
                {
                    printf("    ~ YOU HAVE ALREADY LOOKED AROUND.\n");
                    waitForEnter();
                }
                else 
                {
                    printf("    -> YOU CHOOSE TO LOOK AROUND.\n");
                    look(&player);
                }
                break;
            case 4:
                // LIST COMMANDS
                printf("    LIST OF COMMANDS:\n");
                printf("    1. ATTACK - TRY TO ATTACK THE ENEMY\n");
                printf("    2. HEAL - TRY TO HEAL YOURSELF\n");
                printf("    3. LOOK - LOOK AROUND YOU AND GET INFORMATION\n");
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
            printf(" ACTIONS:    1. MOVE    2. LOOK    3. COMMANDS\n");
            printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");

            printf(" >> ");
            scanf("%d", &input);
            switch (input)
            {
            case 1:
                // MOVE AHEAD
                printf("    -> YOU CHOOSE TO MOVE AHEAD.\n");
                currentSpace += 1; // Increment current space
                hasLooked = 0;
                hasHealed = 0;
                break;
            case 2:
                // LOOK AROUND
                if (hasLooked)
                {
                    printf("    ~ YOU HAVE ALREADY LOOKED AROUND.\n");
                    waitForEnter();
                }
                else 
                {
                    printf("    -> YOU CHOOSE TO LOOK AROUND.\n");
                    look(&player);
                }
                break;
            case 3:
                // LIST COMMANDS
                printf("    LIST OF COMMANDS:\n");
                printf("    1. MOVE - ADVANCES YOU ONE SPACE\n");
                printf("    2. LOOK - LOOK AROUND YOU AND GET INFORMATION\n");
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
}

// change the prototype:
void fight(Enemy *e, Player *p)
{
    int enemyHit = rand() % 100;

    if (enemyHit < 75) {
        int dmg = e->attack - p->defense;
        if (dmg <= 0) { dmg = 0; };
        printf("    -> Enemy hits and deals %d damage!\n", dmg);
        p->health -= dmg;
    } 
    else 
    {
        printf("    ~ Enemy attack misses!\n");
    }

    int playerHit = rand() % 100;

    if (playerHit < 75) {
        int dmg = p->attack - e->defense;
        if (dmg <= 0) 
        { 
            dmg = 1; 
        }

        printf("    -> You hit the enemy and deal %d damage!\n", dmg);
        e->health -= dmg;
    } 
    else 
    {
        printf("    ~ Your attack misses!\n");
    }

    // AFTER ATTACK ROUND WAIT FOR ENTER
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
            enemy.health = 6;
            enemy.attack = 5;
            enemy.defense = 0;
            enemy.id = 1;
            break;
        case SLIME:
            enemy.health = 8;
            enemy.attack = 5;
            enemy.defense = 1;
            enemy.id = 2;
            break;
        case BAT:
            enemy.health = 10;
            enemy.attack = 5;
            enemy.defense = 0;
            enemy.id = 3;
            break;
        case GHOST:
            enemy.health = 20;
            enemy.attack = 7;
            enemy.defense = 2;
            enemy.id = 4;
            break;
        case SKELETON:
            enemy.health = 20;
            enemy.attack = 10;
            enemy.defense = 4;
            enemy.id = 5;
            break;
        case MUMMY:
            enemy.health = 20;
            enemy.attack = 10;
            enemy.defense = 4;
            enemy.id = 6;
            break;
        case MINOTAUR:
            enemy.health = 30;
            enemy.attack = 15;
            enemy.defense = 8;
            enemy.id = 7;
            break;
        case WENDIGOO:
            enemy.health = 30;
            enemy.attack = 15;
            enemy.defense = 18;
            enemy.id = 8;
            break;
        case DRAGON:
            enemy.health = 100;
            enemy.attack = 35;
            enemy.defense = 10;
            enemy.id = 9;
            break;
        default:
        break;
    }
}

void look(Player *p)
{
    int num = rand() % 100;
    int input;

    // FLOOR ONE POSSIBLE FINDS
    if (currentFloor == 1)
    {
        // 10%
        if (num < 10)
        {
            printf("    -> You found a Rusty Sword!\n");
            input = askToEquip();
            if (input == 'Y') { p->attack = 5; p->sword = RUSTY_SWORD; };
        }
        // 10% 
        else if (num < 20)
        {
            printf("    -> You found a Rusty Shield!\n");
            input = askToEquip();
            if (input == 'Y') { p->defense = 3; p->shield = RUSTY_SHIELD; };
        }
        // 5%
        else if (num < 25)
        {
            printf("    -> You found an Iron Short Sword!\n");
            input = askToEquip();
            if (input == 'Y') { p->attack = 7; p->sword = IRON_SHORT_SWORD;};
        }
        // 5%
        else if (num < 30)
        {
            printf("    -> You found an Iron Shield!\n");
            input = askToEquip();
            if (input == 'Y') { p->defense = 4; p->shield = IRON_SHIELD;};
        }
        else 
        {
            printf("    ~ You do not find anything.\n");
        }
        waitForEnter();
    }
    // FLOOR TWO POSSIBLE FINDS
    else if (currentFloor == 2)
    {
        // 10%
        if (num < 10)
        {
            printf("    -> You found an Iron Short Sword!\n");
            input = askToEquip();
            if (input == 'Y') { p->attack = 7; p->sword = IRON_SHORT_SWORD; };
        }
        // 10% 
        else if (num < 20)
        {
            printf("    -> You found an Iron Shield!\n");
            input = askToEquip();
            if (input == 'Y') { p->defense = 4; p->shield = IRON_SHIELD; };
        }
        // 5%
        else if (num < 25)
        {
            printf("    -> You found a Knights Broadsword!\n");
            input = askToEquip();
            if (input == 'Y') { p->attack = 10; p->sword = KNIGHTS_BROADSWORD; };
        }
        // 5%
        else if (num < 30)
        {
            printf("    -> You found a Knights Shield!\n");
            input = askToEquip();
            if (input == 'Y') { p->defense = 6; p->shield = KNGIHTS_SHIELD; };
        }
        else 
        {
            printf("    ~ You do not find anything.\n");
        }

        waitForEnter();
    }
    // FLOOR THREE POSSIBLE FINDS
    else if (currentFloor == 3)
    {
        if (num < 10)
        {
            printf("    -> You found an Excalibur Warsword!\n");
            input = askToEquip();
            if (input == 'Y') { p->attack = 20; p->sword = EXCALIBUR_WARSWORD; };
        }
        else if (num < 20)
        {
            printf("    -> You found a Dragonhide Shield!\n");
            input = askToEquip();
            if (input == 'Y') { p->defense = 15; p->shield = DRAGONHIDE_SHIELD; };
        }
        else 
        {
            printf("    ~ You do not find anything.\n");
        }

        waitForEnter();
    }
    // FLOOR FOUR POSSIBLE FINDS
    else if (currentFloor == 4)
    {
        // 15%
        if (num < 20)
        {
            printf("    -> You found an Excalibur Warsword!\n");
            input = askToEquip();
            if (input == 'Y') { p->attack = 20; p->sword = EXCALIBUR_WARSWORD; };
        }
        // 15%
        else if (num < 40)
        {
            printf("    -> You found a Dragonhide Shield!\n");
            input = askToEquip();
            if (input == 'Y') { p->defense = 15; p->shield = DRAGONHIDE_SHIELD; };
        }
        // 5%
        else if (num < 45)
        {
            printf("    -> You found the Sword of Legend!!!\n");
            input = askToEquip();
            if (input == 'Y') { p->attack = 50; p->sword = SWORD_OF_LEGEND; };
        }
        // 5%
        else if (num < 50)
        {
            printf("    -> You found the Shield of Light!!!\n");
            input = askToEquip();
            if (input == 'Y') { p->defense = 25; p->shield = SHIELD_OF_LIGHT; };
        }
        else 
        {
            printf("    ~ You do not find anything.\n");
        }

        waitForEnter();
    }
    else if (currentFloor == 5)
    {
        // 30%
        if (num < 30)
        {
            printf("    -> You found the Sword of Legend!!!\n");
            input = askToEquip();
            if (input == 'Y') { p->attack = 50; p->sword = SWORD_OF_LEGEND; };
        }
        // 30%
        else if (num < 60)
        {
            printf("    -> You found the Shield of Light!!!\n");
            input = askToEquip();
            if (input == 'Y') { p->defense = 25; p->shield = SHIELD_OF_LIGHT; };
        }
        else 
        {
            printf("    ~ You do not find anything.\n");
        }

        waitForEnter();
    }

    hasLooked = 1;
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

void heal()
{
    int num = rand() % 100;

    // 70% chance to heal
    if (num < 70)
    {
        // 10-40HP
        int healAmt = 10 + rand() % 30;
        printf("    -> You successfully heal %d HP\n", healAmt);
        player.health += healAmt;
        if (player.health > 100) { player.health = 100; };
        timesHealed += 1;
    }
    else 
    {
        printf("    ~ You failed to heal!\n");
    }
    hasHealed = 1;
}

// MAIN GAME LOOP FUNCTION
void game() 
{
    // BASE PLAYER ATTACK AND DEFENSE WITH NOTHING EQUIPPED
                            // DEFAULTS
    player.health   = 100;  // 100
    player.attack   = 3;    // 3
    player.defense  = 2;    // 2
    player.sword    = 0;    // 0
    player.shield   = 0;    // 0

    // WHILE GAME SHOULD RUN -> LOOP
    while(run) 
    {        
        // CLEAR SCREEN BEGINNING OF EACH LOOP
        clearScreen();

        if (currentSpace == 11 && currentFloor == 1)
        {
            // GO TO SECOND FLOOR
            nextFloor();
        }
        else if (currentSpace == 16 && currentFloor == 2)
        {
            // GO TO THIRD FLOOR
            nextFloor();
        }
        else if (currentSpace == 16 && currentFloor == 3)
        {
            // GO TO FOURTH FLOOR
            nextFloor();
        }
        else if (currentSpace == 16 && currentFloor == 4)
        {
            // GO TO FIFTH FLOOR
            nextFloor();
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