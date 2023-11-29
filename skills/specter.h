#pragma once

#include "skill.h"

class Specter : public Skill
{
    public:
        Specter(Game* game);
        ~Specter() {}

        void Use(Ship* source, Ship* target) override;
};