#include "crit_cannon.h"
#include "game.h"

CritCannon::CritCannon(Game* game) : Cannon(game)
{
    cannon_type_ = crit_cannon;
    name_ = "Crit Cannon";
}

void CritCannon::ProcessCrit(Ship* source)
{
    if (source->IsFury())
    {
        crit_ = 2;
        source->IncreaseFury(-1);
    }
    else
    {
        int random = rand() % 100;
        if (random < 30)
            crit_ = 2;
        else
            crit_ = 1;
    }
    OutputCrit(source);
}

void CritCannon::Attack(Ship* source, Ship* target)
{
    ProcessCrit(source);
    target->DecreaseHealth(2 * crit_, source);
    cd_ = 3;
}