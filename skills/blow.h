#pragma once

#include "skill.h"

class Blow : public Skill
{
    public:
        Blow(Game* game);
        ~Blow() {}

        void Use(Ship* source, Ship* target) override;
};