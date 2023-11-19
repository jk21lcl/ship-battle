#include "concatenation_boss.h"
#include "game.h"

ConcatenationBoss::ConcatenationBoss(Game* game, int id) : Ship(game, id)
{
    health_ = 50;
    max_health_ = 50;
    attack_times_ = 5;
    shield_health_ = 20;
    can_stunned_ = false;
    ship_type_ = concatenation_boss;
    name_ = "Concatenation Boss";
    cannons_.push_back(new Cannon1(game));
    cannons_.push_back(new Cannon2(game));
    cannons_.push_back(new Cannon3(game));
    cannons_.push_back(new Cannon4(game));
    cannons_.push_back(new Cannon5(game));
    cannons_.push_back(new SplitCannon(game));
    cannons_.push_back(new StunningCannon(game));
    cannons_.push_back(new ExplosiveCannon(game));
    cannons_.push_back(new HealCannon(game));
    cannons_.push_back(new CritCannon(game));
    cannons_.push_back(new SuperCritCannon(game));
    cannons_.push_back(new Torpedo(game));
    skills_.push_back(new Shield(game));
    skills_.push_back(new Suck(game));
    skills_.push_back(new Heal(game));
    skills_.push_back(new Fury(game));
    skills_.push_back(new Dodge(game));
    skills_.push_back(new Grapeshot(game));
    skills_.push_back(new SuperGrapeshot(game));
}

void ConcatenationBoss::DecreaseHealth(double n, Ship* source)
{
    if (source && source->IsSuck())
        source->IncreaseHealth(n);
    if (shield_health_)
    {
        shield_health_ -= n;
        if (source)
            source->DecreaseHealth(n, nullptr);
    }
    else
    {
        if (health_ >= 40)
            n -= 2;
        else
            n -= 1;
        if (n > 0)
            health_ -= n;
    }
    if (shield_health_ <= 0)
        shield_health_ = 0;
    if (health_ <= 0)
    {
        health_ = 0;
        alive_ = false;
    }
    Ban();
}