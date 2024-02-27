#include "untime_bomb.h"
#include "game.h"

UntimeBomb::UntimeBomb(Game* game) : Skill(game)
{
    skill_type_ = untime_bomb;
    name_ = "Untime Bomb";
    target_type_ = enemy;
    max_cd_ = 2;
}

void UntimeBomb::Use(Ship* source, Ship* target)
{
    target->AddAccessory(untime_bomb_acc);
}