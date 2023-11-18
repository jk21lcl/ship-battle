#include "super_heal.h"
#include "game.h"

SuperHeal::SuperHeal(Game* game) : Skill(game)
{
    skill_type_ = super_heal;
    name_ = "Super Heal";
    attack_times_ = 0;
    max_cd_ = 4;
}

void SuperHeal::Use(Ship* source, Ship* target)
{
    for (Ship* ship : game_->GetCurPlayer()->GetShips())
        ship->IncreaseHealth(4);
}