#include "stunning_cannon.h"
#include "game.h"

StunningCannon::StunningCannon(Game* game) : Cannon(game)
{
    cannon_type_ = stunning_cannon;
    name_ = "Stunning Cannon";
}

void StunningCannon::Attack(Ship* source, Ship* target)
{
    if (!target->HasShield() && !target->IsImmune() && !(target->GetShipType() == wizard_ship))
        target->IncreaseStun(2);
    cd_ = 4;
}