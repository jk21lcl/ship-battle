#include "cannon_1.h"
#include "game.h"

Cannon1::Cannon1(Game* game) : Cannon(game)
{
    cannon_type_ = cannon_1;
    name_ = "Cannon1";
    max_cd_ = 1;
}

void Cannon1::Attack(Ship* source, Ship* target)
{
    ProcessCrit(source, target);
    if (!ProcessDodge(source, target))
        target->DecreaseHealth(1 * crit_, source);
}