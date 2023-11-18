#include "cannon_3.h"
#include "game.h"

Cannon3::Cannon3(Game* game) : Cannon(game)
{
    cannon_type_ = cannon_3;
    name_ = "Cannon3";
    max_cd_ = 3;
}

void Cannon3::Attack(Ship* source, Ship* target)
{
    ProcessCrit(source, target);
    if (!ProcessDodge(source, target))
        target->DecreaseHealth(3 * crit_, source);
    source->IncreaseHealth(1);
}