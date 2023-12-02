#pragma once

#include "skill.h"

class Stab : public Skill
{
    public:
        Stab(Game* game);
        ~Stab() {}

        void Use(Ship* source, Ship* target) override;
};