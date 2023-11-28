#pragma once

#include "skill.h"

class RandomBuff : public Skill
{
    public:
        RandomBuff(Game* game);
        ~RandomBuff() {}

        void Use(Ship* source, Ship* target) override;
};