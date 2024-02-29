#include "heal.h"
#include "game.h"

Heal::Heal(Game* game) : Skill(game)
{
    skill_type_ = heal;
    name_ = "Heal";
    max_cd_ = 3;
}

void Heal::Use(Ship* source, Ship* target)
{
    target->IncreaseEffect(heal_eff, 3);
}