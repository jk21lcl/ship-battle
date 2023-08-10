#pragma once

#include "skill.h"

class SuperHeal : public Skill
{
    public:
        SuperHeal(Game* game);
        ~SuperHeal() {}

        void Use(Ship* source, Ship* target) override;
};