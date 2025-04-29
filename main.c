#include <stdio.h>
#include "player.h"
#include "enemy.h"
#include "game.h"

int menu();
void info();

const char logo[] = "  _____ _   _ _____   ____  _   _ _   _  ____ _____ ___  _   _ \n"
                    " |_   _| | | | ____| |  _ \\| | | | \\ | |/ ___| ____/ _ \\| \\ | |\n"
                    "   | | | |_| |  _|   | | | | | | |  \\| | |  _|  _|| | | |  \\| |\n"
                    "   | | |  _  | |___  | |_| | |_| | |\\  | |_| | |__| |_| | |\\  |\n"
                    "   |_| |_| |_|_____| |____/ \\___/|_| \\_|\\____|_____\\___/|_| \\_|\n";

int main()
{ 
    srand((unsigned)time(NULL));

    int menuInput;

    clearScreen();
    menuInput = menu();

    if (menuInput == 1)
    {
        game();
    }
    else if (menuInput == 2)
    {
        info();
    }
    else 
    {
        printf("INVALID INPUT.\n");
        menuInput = menu();
    }

}

int menu()
{
    int input;

    printf("%s\n", logo);
    printf("    VER. 1.1\n\n");
    printf("    1. START GAME\n");
    printf("    2. INFO\n\n");

    printf("    >> ");
    scanf("%d", &input);

    while (input != 1 && input != 2) {
        printf("    INVALID INPUT!\n>> ");
        scanf("%d", &input);
    }

    switch (input)
    {
    case 1:
        return 1;
        break;
    case 2:
        return 2;
        break;
    default:
        return 1;
        break;
    }
}

void info()
{
    printf("\n    Game by Hayden Baer\n");
    printf("    =-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("    Started Project: 4/24/25\n");
    printf("    VERSION: 1.1 | 4/29/25\n");
    printf("    =-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");
}