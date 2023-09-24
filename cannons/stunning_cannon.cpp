#include "stunning_cannon.h"
#include "game.h"

StunningCannon::StunningCannon(Game* game) : Cannon(game)
{
    cannon_type_ = stunning_cannon;
    name_ = "Stunning Cannon";
}

void StunningCannon::Attack(Ship* source, Ship* target)
{
    if (!ProcessDodge(source, target))
        if (!target->HasShield() && !target->IsImmune())
        {
            ShipType type = target->GetShipType();
            if (type != wizard_ship && type != small_explosive_ship && 
                type != medium_explosive_ship && type != big_explosive_ship)
            target->IncreaseStun(1);
        }
    cd_ = 4;
}