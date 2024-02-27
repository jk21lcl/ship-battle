#include "time_bomb.h"
#include "game.h"

TimeBomb::TimeBomb(Game* game) : Skill(game)
{
    skill_type_ = time_bomb;
    name_ = "Time Bomb";
    target_type_ = enemy;
    max_cd_ = 2;
}

void TimeBomb::Use(Ship* source, Ship* target)
{
    target->AddAccessory(time_bomb_acc);
}