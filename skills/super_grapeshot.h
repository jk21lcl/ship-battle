#pragma once

#include "skill.h"

class SuperGrapeshot : public Skill
{
    public:
        SuperGrapeshot(Game* game);
        ~SuperGrapeshot() {}

        void Use(Ship* source, Ship* target) override;
        void ProcessCrit(Ship* source, Ship* target) override;
};