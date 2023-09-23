#include "grapeshot.h"
#include "game.h"

Grapeshot::Grapeshot(Game* game) : Skill(game)
{
    skill_type_ = grapeshot;
    name_ = "Grapeshot";
}

void Grapeshot::Use(Ship* source, Ship* target)
{
    target->DecreaseHealth(2, source);
    cd_ = 2;
}