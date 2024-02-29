#include "dodge.h"
#include "game.h"

Dodge::Dodge(Game* game) : Skill(game)
{
    skill_type_ = dodge;
    name_ = "Dodge";
    max_cd_ = 3;
}

void Dodge::Use(Ship* source, Ship* target)
{
    target->IncreaseEffect(dodge_eff, 2);
}