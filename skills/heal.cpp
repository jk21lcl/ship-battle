#include "heal.h"
#include "game.h"

Heal::Heal(Game* game) : Skill(game)
{
    skill_type_ = heal;
    name_ = "Heal";
}

void Heal::Use(Ship* source, Ship* target)
{
    target->IncreaseHeal(3);
    cd_ = 3;
}