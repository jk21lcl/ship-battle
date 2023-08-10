#include "immune.h"
#include "game.h"

Immune::Immune(Game* game) : Skill(game)
{
    skill_type_ = immune;
    name_ = "Immune";
}

void Immune::Use(Ship* source, Ship* target)
{
    target->IncreaseImmune(2);
    cd_ = 3;
}