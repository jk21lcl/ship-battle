#include "cannon_3.h"
#include "game.h"

Cannon3::Cannon3(Game* game) : Cannon(game)
{
    cannon_type_ = cannon_3;
    name_ = "Cannon3";
}

void Cannon3::Attack(Ship* source, Ship* target)
{
    target->DecreaseHealth(3, source);
    source->IncreaseHealth(1);
    cd_ = 4;
}