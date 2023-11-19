#include "cannon_4.h"
#include "game.h"

Cannon4::Cannon4(Game* game) : Cannon(game)
{
    cannon_type_ = cannon_4;
    name_ = "Cannon4";
    max_cd_ = 4;
    ban_health_ = 10;
}

void Cannon4::Attack(Ship* source, Ship* target)
{
    ProcessCrit(source, target);
    if (!ProcessDodge(source, target))
        target->DecreaseHealth(4 * crit_, source);
    source->IncreaseHealth(2);
}