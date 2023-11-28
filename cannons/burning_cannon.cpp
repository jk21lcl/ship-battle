#include "burning_cannon.h"
#include "game.h"

BurningCannon::BurningCannon(Game* game) : Cannon(game)
{
    cannon_type_ = burning_cannon;
    name_ = "Burning Cannon";
    max_cd_ = 3;
    ban_health_ = 6;
}

void BurningCannon::Attack(Ship* source, Ship* target)
{
    ProcessCrit(source, target);
    OutputCrit(source, target);
    if (!ProcessDodge(source, target))
    {
        target->DecreaseHealth(2 * crit_, source);
        target->IncreaseBurn(2);
    }
}