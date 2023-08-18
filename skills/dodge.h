#pragma once

#include "skill.h"

class Dodge : public Skill
{
    public:
        Dodge(Game* game);
        ~Dodge() {}

        void Use(Ship* source, Ship* target) override;
};