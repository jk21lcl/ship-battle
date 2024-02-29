#include "suck.h"
#include "game.h"

Suck::Suck(Game* game) : Skill(game)
{
    skill_type_ = suck;
    name_ = "Suck";
    max_cd_ = 2;
}

void Suck::Use(Ship* source, Ship* target)
{
    target->IncreaseEffect(suck_eff, 2);
}