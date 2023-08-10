#include "shield.h"
#include "game.h"

Shield::Shield(Game* game) : Skill(game)
{
    skill_type_ = shield;
    name_ = "Shield";
}

void Shield::Attack(Ship* source, Ship* target)
{
    target->IncreaseShieldHealth(5);
    cd_ = 3;
}