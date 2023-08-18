#include "explosive_cannon.h"
#include "game.h"

ExplosiveCannon::ExplosiveCannon(Game* game) : Cannon(game)
{
    cannon_type_ = explosive_cannon;
    name_ = "Explosive Cannon";
}

void ExplosiveCannon::SpecialAttack(Ship* source, Ship* main_target, 
                                    Ship* splash_target_1, Ship* splash_target_2)
{
    ProcessCrit(source);
    main_target->DecreaseHealth(4 * crit_, source);
    if (splash_target_1)
        splash_target_1->DecreaseHealth(2 * crit_, source);
    if (splash_target_2)
        splash_target_2->DecreaseHealth(2 * crit_, source);
    cd_ = 5;
}