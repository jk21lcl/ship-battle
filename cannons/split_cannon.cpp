#include "split_cannon.h"
#include "game.h"

SplitCannon::SplitCannon(Game* game) : Cannon(game)
{
    cannon_type_ = split_cannon;
    name_ = "Split Cannon";
}

void SplitCannon::Attack(Ship* source, Ship* target)
{
    target->DecreaseHealth(1, source);
    cd_ = 3;
}