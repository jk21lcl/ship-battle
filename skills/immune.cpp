#include "immune.h"
#include "game.h"

Immune::Immune(Game* game) : Skill(game)
{
    skill_type_ = immune;
    name_ = "Immune";
    attack_times_ = 2;
    max_cd_ = 3;
}

void Immune::Use(Ship* source, Ship* target)
{
    target->IncreaseImmune(2);
}