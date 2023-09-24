#include "small_explode.h"
#include "game.h"

SmallExplode::SmallExplode(Game* game) : Skill(game)
{
    skill_type_ = small_explode;
    name_ = "Small Explode";
    cd_ = 1;
}

void SmallExplode::Use(Ship* source, Ship* target)
{
    double damage = 5;
    if (source->HasShield())
        damage += source->GetShieldHealth();
    target->DecreaseHealth(damage, source);
    source->SetDead();
}