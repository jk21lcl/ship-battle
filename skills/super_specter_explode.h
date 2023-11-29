#pragma once

#include "skill.h"

class SuperSpecterExplode : public Skill
{
    public:
        SuperSpecterExplode(Game* game);
        ~SuperSpecterExplode() {}

        void Use(Ship* source, Ship* target) override;
};