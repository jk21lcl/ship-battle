#include "heal_cannon.h"
#include "game.h"

HealCannon::HealCannon(Game* game) : Cannon(game)
{
    cannon_type_ = heal_cannon;
    name_ = "Heal Cannon";
    max_cd_ = 3;
    target_type_ = ally;
}

void HealCannon::Attack(Ship* source, Ship* target)
{
    target->IncreaseHealth(5);
}