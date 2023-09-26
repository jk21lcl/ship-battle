#include "grapeshot.h"
#include "game.h"

Grapeshot::Grapeshot(Game* game) : Skill(game)
{
    skill_type_ = grapeshot;
    name_ = "Grapeshot";
}

void Grapeshot::ProcessCrit(Ship* source, Ship* target)
{
    if (source->IsFury())
    {
        crit_ = 2;
        source->IncreaseFury(-1);
    }
    else
        crit_ = 1;
}

void Grapeshot::Use(Ship* source, Ship* target)
{
    ProcessCrit(source, target);
    for (Ship* ship : game_->GetOtherPlayer()->GetShips())
    {
        if (ship->IsAlive())
        {
            OutputCrit(source, ship);
            if (!ProcessDodge(source, ship))
                ship->DecreaseHealth(2 * crit_, source);
        }
    }
    cd_ = 3;
}