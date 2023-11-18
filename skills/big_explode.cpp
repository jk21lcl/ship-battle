#include "big_explode.h"
#include "game.h"

BigExplode::BigExplode(Game* game) : Skill(game)
{
    skill_type_ = big_explode;
    name_ = "Big Explode";
    skill_property_ = attack_skill;
    target_type_ = enemy;
    max_cd_ = 0;
    cd_ = 3;
}

void BigExplode::Use(Ship* source, Ship* target)
{
    double damage = 12;
    if (source->HasShield())
        damage += source->GetShieldHealth();
    target->DecreaseHealth(damage, source);
    int id = target->GetId();
    vector<Ship*> ships = game_->GetOtherPlayer()->GetShips();
    int num = game_->GetOtherPlayer()->GetNum();
    if (id != 1)
        ships[id - 2]->DecreaseHealth(damage * 0.5, source);
    if (id != num)
        ships[id]->DecreaseHealth(damage * 0.5, source);
    source->SetDead();
}