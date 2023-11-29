#include "specter_cannon.h"
#include "game.h"

SpecterCannon::SpecterCannon(Game* game) : Cannon(game)
{
    cannon_type_ = specter_cannon;
    name_ = "Specter Cannon";
    max_cd_ = 1;
}

void SpecterCannon::Attack(Ship* source, Ship* target)
{
    ProcessCrit(source, target);
    OutputCrit(source, target);
    if (!ProcessDodge(source, target))
        target->DecreaseHealth(1 * crit_, source);
    SpecterShip* specter_ship = dynamic_cast<SpecterShip*>(source);
    specter_ship->IncreaseSpecter(1);
}