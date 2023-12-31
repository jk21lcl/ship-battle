#include "explosive_cannon.h"
#include "game.h"

ExplosiveCannon::ExplosiveCannon(Game* game) : Cannon(game)
{
    cannon_type_ = explosive_cannon;
    name_ = "Explosive Cannon";
    max_cd_ = 4;
    ban_health_ = 8;
}

void ExplosiveCannon::Attack(Ship* source, Ship* target)
{
    ProcessCrit(source, target);
    OutputCrit(source, target);
    if (!ProcessDodge(source, target))
    {
        target->DecreaseHealth(4 * crit_, source);
        int id = target->GetId();
        vector<Ship*> ships = game_->GetOtherPlayer()->GetShips();
        int num = game_->GetOtherPlayer()->GetNum();
        if (id != 1)
        {
            ships[id - 2]->DecreaseHealth(2 * crit_, source);
            OutputCrit(source, ships[id - 2]);
        }
        if (id != num)
        {
            ships[id]->DecreaseHealth(2 * crit_, source);
            OutputCrit(source, ships[id]);
        }
    }
}