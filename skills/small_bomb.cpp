#include "small_bomb.h"
#include "game.h"

SmallBomb::SmallBomb(Game* game) : Skill(game)
{
    skill_type_ = small_bomb;
    name_ = "Small Bomb";
    target_type_ = enemy;
    max_cd_ = 2;
}

void SmallBomb::Use(Ship* source, Ship* target)
{
    target->AddAccessory(small_bomb_acc);
}