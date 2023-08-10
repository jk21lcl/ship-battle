#pragma once

#include "skill.h"

class Heal : public Skill
{
    public:
        Heal(Game* game);
        ~Heal() {}

        void Use(Ship* source, Ship* target) override;
};