#include "big_bomb.h"
#include "game.h"

BigBomb::BigBomb(Game* game) : Skill(game)
{
    skill_type_ = big_bomb;
    name_ = "Big Bomb";
    target_type_ = enemy;
    max_cd_ = 2;
}

void BigBomb::Use(Ship* source, Ship* target)
{
    target->AddAccessory(big_bomb_acc);
}