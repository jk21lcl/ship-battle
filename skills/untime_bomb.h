#pragma once

#include "skill.h"

class UntimeBomb : public Skill
{
    public:
        UntimeBomb(Game* game);
        ~UntimeBomb() {}

        void Use(Ship* source, Ship* target) override;
};