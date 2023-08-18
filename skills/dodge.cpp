#include "dodge.h"
#include "game.h"

Dodge::Dodge(Game* game) : Skill(game)
{
    skill_type_ = dodge;
    name_ = "Dodge";
}

void Dodge::Use(Ship* source, Ship* target)
{
    target->IncreaseDodge(2);
    cd_ = 3;
}