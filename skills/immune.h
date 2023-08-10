#pragma once

#include "skill.h"

class Immune : public Skill
{
    public:
        Immune(Game* game);
        ~Immune() {}

        void Use(Ship* source, Ship* target) override;
};