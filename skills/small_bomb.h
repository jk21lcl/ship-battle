#pragma once

#include "skill.h"

class SmallBomb : public Skill
{
    public:
        SmallBomb(Game* game);
        ~SmallBomb() {}

        void Use(Ship* source, Ship* target) override;
};