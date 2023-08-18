#pragma once

#include "skill.h"

class Fury : public Skill
{
    public:
        Fury(Game* game);
        ~Fury() {}

        void Use(Ship* source, Ship* target) override;
};