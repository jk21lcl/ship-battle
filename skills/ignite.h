#pragma once

#include "skill.h"

class Ignite : public Skill
{
    public:
        Ignite(Game* game);
        ~Ignite() {}

        void Use(Ship* source, Ship* target) override;
};