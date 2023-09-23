#include "super_shield.h"
#include "game.h"

SuperShield::SuperShield(Game* game) : Skill(game)
{
    skill_type_ = super_shield;
    name_ = "Super Shield";
}

void SuperShield::Use(Ship* source, Ship* target)
{
    target->IncreaseShieldHealth(2);
    cd_ = 4;
}