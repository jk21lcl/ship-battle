#pragma once

#include "skill.h"

class TimeBomb : public Skill
{
    public:
        TimeBomb(Game* game);
        ~TimeBomb() {}

        void Use(Ship* source, Ship* target) override;
};