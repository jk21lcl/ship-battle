#include "super_shield.h"
#include "game.h"

SuperShield::SuperShield(Game* game) : Skill(game)
{
    skill_type_ = super_shield;
    name_ = "Super Shield";
    attack_times_ = 0;
    max_cd_ = 4;
}

void SuperShield::Use(Ship* source, Ship* target)
{
    for (Ship* ship : game_->GetCurPlayer()->GetShips())
        ship->IncreaseShieldHealth(2);
    cd_ = 4;
}