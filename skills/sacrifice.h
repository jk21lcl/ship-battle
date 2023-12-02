#pragma once

#include "skill.h"

class Sacrifice : public Skill
{
    public:
        Sacrifice(Game* game);
        ~Sacrifice() {}

        void Use(Ship* source, Ship* target) override;
};