#pragma once

#include "skill.h"

class BigBomb : public Skill
{
    public:
        BigBomb(Game* game);
        ~BigBomb() {}

        void Use(Ship* source, Ship* target) override;
};