#include "stunning_cannon.h"
#include "game.h"

StunningCannon::StunningCannon(Game* game) : Cannon(game)
{
    cannon_type_ = stunning_cannon;
    name_ = "Stunning Cannon";
    max_cd_ = 3;
    ban_health_ = 4;
    attack_times_ = 2;
}

void StunningCannon::Attack(Ship* source, Ship* target)
{
    if (!ProcessDodge(source, target))
        if (!target->HasShield() && !target->IsImmune() && target->GetCanStunned())
        {
            target->IncreaseStun(1);
        }
}