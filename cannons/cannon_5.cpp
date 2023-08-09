#include "cannon_5.h"
#include "game.h"

Cannon5::Cannon5(Game* game) : Cannon(game)
{
    cannon_type_ = cannon_5;
    name_ = "Cannon5";
}

void Cannon5::Attack(Ship* source, Ship* target)
{
    target->DecreaseHealth(5, source);
    source->IncreaseHealth(3);
    cd_ = 6;
}