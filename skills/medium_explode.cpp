#include "medium_explode.h"
#include "game.h"

MediumExplode::MediumExplode(Game* game) : Skill(game)
{
    skill_type_ = medium_explode;
    name_ = "Medium Explode";
    skill_property_ = attack_skill;
    target_type_ = enemy;
    max_cd_ = 0;
    cd_ = 2;
}

void MediumExplode::Use(Ship* source, Ship* target)
{
    double damage = 8;
    damage += source->FindEffect(shield_eff);
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