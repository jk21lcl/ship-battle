#include "cannon_2.h"
#include "game.h"

Cannon2::Cannon2(Game* game) : Cannon(game)
{
    cannon_type_ = cannon_2;
    name_ = "Cannon2";
    cd_ = 0;
}

void Cannon2::Attack(Ship* source, Ship* target)
{
    if (!target->HasShield())
        target->IncreaseStun(1);
    target->DecreaseHealth(2, source);
    cd_ = 3;
}