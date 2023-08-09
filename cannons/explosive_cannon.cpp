#include "explosive_cannon.h"
#include "game.h"

ExplosiveCannon::ExplosiveCannon(Game* game) : Cannon(game)
{
    cannon_type_ = explosive_cannon;
    name_ = "Explosive Cannon";
    cd_ = 2;
}

void ExplosiveCannon::SpecialAttack(Ship* source, Ship* main_target, 
                                    Ship* splash_target_1, Ship* splash_target_2)
{
    main_target->DecreaseHealth(4, source);
    if (splash_target_1)
        splash_target_1->DecreaseHealth(2, source);
    if (splash_target_2)
        splash_target_2->DecreaseHealth(2, source);
    cd_ = 5;
}