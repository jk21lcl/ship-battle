#include "shield.h"
#include "game.h"

Shield::Shield(Game* game) : Cannon(game)
{
    cannon_type_ = shield;
    name_ = "Shield";
    cd_ = 2;
}

void Shield::Attack(Ship* source, Ship* target)
{
    target->IncreaseShieldHealth(3);
    cd_ = 4;
}