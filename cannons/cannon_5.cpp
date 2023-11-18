#include "cannon_5.h"
#include "game.h"

Cannon5::Cannon5(Game* game) : Cannon(game)
{
    cannon_type_ = cannon_5;
    name_ = "Cannon5";
    max_cd_ = 5;
}

void Cannon5::Attack(Ship* source, Ship* target)
{
    ProcessCrit(source, target);
    if (!ProcessDodge(source, target))
        target->DecreaseHealth(5 * crit_, source);
    source->IncreaseHealth(3);
}