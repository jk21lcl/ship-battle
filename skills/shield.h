#pragma once

#include "skill.h"

class Shield : public Skill
{
    public:
        Shield(Game* game);
        ~Shield() {}

        void Use(Ship* source, Ship* target) override;
};