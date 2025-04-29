#ifndef ITEM_H
#define ITEM_H

#include <stdio.h>

// ITEMS
typedef enum
{
    RUSTY_SWORD         = 1,
    IRON_SHORT_SWORD    = 2,
    KNIGHTS_BROADSWORD  = 3,
    EXCALIBUR_WARSWORD  = 4,
    SWORD_OF_LEGEND     = 5
} SwordID;

typedef enum
{
    RUSTY_SWORD_ATK         = 5,
    IRON_SHORT_SWORD_ATK    = 7,
    KNIGHTS_BROADSWORD_ATK  = 10,
    EXCALIBUR_WARSWORD_ATK  = 14,
    SWORD_OF_LEGEND_ATK     = 20
} SwordDMG;

typedef enum
{
    RUSTY_SHIELD        = 1,
    IRON_SHIELD         = 2,
    KNIGHTS_SHIELD      = 3,
    DRAGONHIDE_SHIELD   = 4,
    SHIELD_OF_LIGHT     = 5
} ShieldID;

typedef enum
{
    RUSTY_SHIELD_DF        = 3,
    IRON_SHIELD_DF         = 4,
    KNIGHTS_SHIELD_DF      = 6,
    DRAGONHIDE_SHIELD_DF   = 8,
    SHIELD_OF_LIGHT_DF     = 12
} ShieldDF;

#endif