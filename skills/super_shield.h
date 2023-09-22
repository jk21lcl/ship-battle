#pragma once

#include "skill.h"

class SuperShield : public Skill
{
    public:
        SuperShield(Game* game);
        ~SuperShield() {}

        void Use(Ship* source, Ship* target) override;
};