#include "ignite.h"
#include "game.h"

Ignite::Ignite(Game* game) : Skill(game)
{
    skill_type_ = ignite;
    name_ = "Ignite";
    max_cd_ = 3;
    attack_times_ = 2;
    target_type_ = enemy;
}

void Ignite::Use(Ship* source, Ship* target)
{
    if (!ProcessDodge(source, target))
        target->IncreaseEffect(burn_eff, 1);
}