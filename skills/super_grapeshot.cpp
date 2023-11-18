#include "super_grapeshot.h"
#include "game.h"

SuperGrapeshot::SuperGrapeshot(Game* game) : Skill(game)
{
    skill_type_ = super_grapeshot;
    name_ = "Super Grapeshot";
    skill_property_ = attack_skill;
    attack_times_ = 0;
    max_cd_ = 5;
}

void SuperGrapeshot::Use(Ship* source, Ship* target)
{
    ProcessCrit(source, target);
    for (Ship* ship : game_->GetOtherPlayer()->GetShips())
    {
        if (ship->IsAlive())
        {
            OutputCrit(source, ship);
            if (!ProcessDodge(source, ship))
                ship->DecreaseHealth(4 * crit_, source);
        }
    }
}