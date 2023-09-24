#pragma once

#include "skill.h"

class SmallExplode : public Skill
{
    public:
        SmallExplode(Game* game);
        ~SmallExplode() {}

        void Use(Ship* source, Ship* target) override;
};