#include "lock.h"
#include "game.h"

Lock::Lock(Game* game) : Skill(game)
{
    skill_type_ = lock;
    name_ = "Lock";
    target_type_ = enemy;
    max_cd_ = 2;
}

void Lock::Use(Ship* source, Ship* target)
{
    target->IncreaseLock(1);
}