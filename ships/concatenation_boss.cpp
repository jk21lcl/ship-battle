#include "concatenation_boss.h"
#include "game.h"

ConcatenationBoss::ConcatenationBoss(Game* game, int id) : Ship(game, id)
{
    health_ = 60;
    max_health_ = 60;
    attack_times_ = 4;
    shield_health_ = 20;
    can_stunned_ = false;
    dodge_prob_ = 25;
    heal_health_ = 2;
    shield_rebound_ = 100;
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
    skills_.push_back(new Heal(game));
    skills_.push_back(new Fury(game));
    skills_.push_back(new Dodge(game));
    skills_.push_back(new Grapeshot(game));
    Update();
}

void ConcatenationBoss::Update()
{
    if (health_ > 30)
    {
        absolute_damage_reduce_ = 1;
        ratio_damage_reduce_ = 0;
    }
    else
    {
        absolute_damage_reduce_ = 0;
        ratio_damage_reduce_ = 20;
    }
}