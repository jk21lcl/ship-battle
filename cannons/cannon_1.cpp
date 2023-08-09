#include "cannon_1.h"
#include "game.h"

Cannon1::Cannon1(Game* game) : Cannon(game)
{
    cannon_type_ = cannon_1;
    name_ = "Cannon1";
}

void Cannon1::Attack(Ship* source, Ship* target)
{
    target->DecreaseHealth(1, source);
    cd_ = 2;
}