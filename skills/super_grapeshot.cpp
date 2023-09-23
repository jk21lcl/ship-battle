#include "super_grapeshot.h"
#include "game.h"

SuperGrapeshot::SuperGrapeshot(Game* game) : Skill(game)
{
    skill_type_ = super_grapeshot;
    name_ = "Super Grapeshot";
}

void SuperGrapeshot::Use(Ship* source, Ship* target)
{
    target->DecreaseHealth(4, source);
    cd_ = 5;
}