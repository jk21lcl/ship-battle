#include "super_heal.h"
#include "game.h"

SuperHeal::SuperHeal(Game* game) : Skill(game)
{
    skill_type_ = super_heal;
    name_ = "Super Heal";
}

void SuperHeal::Use(Ship* source, Ship* target)
{
    target->IncreaseHealth(4);
    cd_ = 4;
}