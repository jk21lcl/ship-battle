#include "fury.h"
#include "game.h"

Fury::Fury(Game* game) : Skill(game)
{
    skill_type_ = fury;
    name_ = "Fury";
    max_cd_ = 3;
}

void Fury::Use(Ship* source, Ship* target)
{
    target->IncreaseEffect(fury_eff, 1);
}