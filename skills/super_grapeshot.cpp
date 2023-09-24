#include "super_grapeshot.h"
#include "game.h"

SuperGrapeshot::SuperGrapeshot(Game* game) : Skill(game)
{
    skill_type_ = super_grapeshot;
    name_ = "Super Grapeshot";
}

void SuperGrapeshot::ProcessCrit(Ship* source, Ship* target)
{
    if (source->IsFury())
    {
        crit_ = 2;
        source->IncreaseFury(-1);
    }
    else
        crit_ = 1;
}

void SuperGrapeshot::Use(Ship* source, Ship* target)
{
    ProcessCrit(source, target);
    for (Ship* ship : game_->GetOtherPlayer()->GetShips())
    {
        OutputCrit(source, ship);
        if (!ProcessDodge(source, ship))
            ship->DecreaseHealth(4 * crit_, source);
    }
    cd_ = 6;
}