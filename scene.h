#ifndef SCENE_H
#define SCENE_H

#include <stdio.h>

// ALL SCENE ID'S
typedef enum
{
    INTRO       = 0,
    NOTHING     = 1,
    RAT         = 2,
    SLIME       = 3,
    BAT         = 4,
    GHOST       = 5,
    IMP         = 6,
    SKELETON    = 7,
    MUMMY       = 8,
    MINOTAUR    = 9,
    WENDIGOO    = 10,
    DRAGON      = 11,
    STAIRS      = 12
} SceneID;

// INTRO SCENE
void sceneIntro();

// EMPTY SCREEN - NO ENCOUNTER
void sceneNothing();

void sceneStairs();

// FLOOR ONE SCENES
void sceneRat();
void sceneSlime();
void sceneBat();

// FLOOR TWO SCENES
void sceneGhost();
void sceneImp();

// FLOOR THREE SCENES
void sceneSkeleton();
void sceneMummy();

// FLOOR FOUR SCENES
void sceneMinotaur();
void sceneWendigoo();

// FLOOR FIVE SCENE
void sceneDragon();

#endif