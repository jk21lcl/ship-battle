#pragma once

#include "skill.h"

class Lock : public Skill
{
    public:
        Lock(Game* game);
        ~Lock() {}

        void Use(Ship* source, Ship* target) override;
};