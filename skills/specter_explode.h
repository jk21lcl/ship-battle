#pragma once

#include "skill.h"

class SpecterExplode : public Skill
{
    public:
        SpecterExplode(Game* game);
        ~SpecterExplode() {}

        void Use(Ship* source, Ship* target) override;
};