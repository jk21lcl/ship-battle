#include "shield.h"
#include "game.h"

Shield::Shield(Game* game) : Skill(game)
{
    skill_type_ = shield;
    name_ = "Shield";
    max_cd_ = 3;
}

void Shield::Use(Ship* source, Ship* target)
{
    target->IncreaseEffect(shield_eff, 5);
}