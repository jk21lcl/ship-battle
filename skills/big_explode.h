#pragma once

#include "skill.h"

class BigExplode : public Skill
{
    public:
        BigExplode(Game* game);
        ~BigExplode() {}

        void Use(Ship* source, Ship* target) override;
};