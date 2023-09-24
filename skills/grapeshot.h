#pragma once

#include "skill.h"

class Grapeshot : public Skill
{
    public:
        Grapeshot(Game* game);
        ~Grapeshot() {}

        void Use(Ship* source, Ship* target) override;
        void ProcessCrit(Ship* source, Ship* target) override;
};