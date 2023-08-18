#include "super_crit_cannon.h"
#include "game.h"

SuperCritCannon::SuperCritCannon(Game* game) : Cannon(game)
{
    cannon_type_ = super_crit_cannon;
    name_ = "Super Crit Cannon";
}

void SuperCritCannon::ProcessCrit(Ship* source)
{
    if (source->IsFury())
    {
        crit_ = 2;
        source->IncreaseFury(-1);
    }
    else
    {
        int random = rand() % 100;
        if (random < 40)
            crit_ = 2;
        else if (random < 60)
            crit_ = 3;
        else
            crit_ = 1;
    }
    OutputCrit(source);
}

void SuperCritCannon::Attack(Ship* source, Ship* target)
{
    ProcessCrit(source);
    target->DecreaseHealth(3 * crit_, source);
    cd_ = 5;
}