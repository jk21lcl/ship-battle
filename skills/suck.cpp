#include "suck.h"
#include "game.h"

Suck::Suck(Game* game) : Skill(game)
{
    skill_type_ = suck;
    name_ = "Suck";
}

void Suck::Use(Ship* source, Ship* target)
{
    target->IncreaseSuck(2);
    cd_ = 2;
}