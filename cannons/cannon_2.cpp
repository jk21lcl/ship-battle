#include "cannon_2.h"
#include "game.h"

Cannon2::Cannon2(Game* game) : Cannon(game)
{
    cannon_type_ = cannon_2;
    name_ = "Cannon2";
}

void Cannon2::Attack(Ship* source, Ship* target)
{
    ProcessCrit(source, target);
    if (!ProcessDodge(source, target))
    {
        if (!target->HasShield() && !target->IsImmune() && !(target->GetShipType() == wizard_ship))
            target->IncreaseStun(1);
        target->DecreaseHealth(2 * crit_, source);
    }
    cd_ = 3;
}