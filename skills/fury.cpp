#include "fury.h"
#include "game.h"

Fury::Fury(Game* game) : Skill(game)
{
    skill_type_ = fury;
    name_ = "Fury";
}

void Fury::Use(Ship* source, Ship* target)
{
    target->IncreaseFury(1);
    cd_ = 3;
}