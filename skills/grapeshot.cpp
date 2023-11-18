#include "grapeshot.h"
#include "game.h"

Grapeshot::Grapeshot(Game* game) : Skill(game)
{
    skill_type_ = grapeshot;
    name_ = "Grapeshot";
    skill_property_ = attack_skill;
    attack_times_ = 0;
    max_cd_ = 2;
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
}