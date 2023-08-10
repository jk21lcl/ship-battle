#pragma once

#include "skill.h"

class Suck : public Skill
{
    public:
        Suck(Game* game);
        ~Suck() {}

        void Use(Ship* source, Ship* target) override;
};