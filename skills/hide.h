#pragma once

#include "skill.h"

class Hide : public Skill
{
    public:
        Hide(Game* game);
        ~Hide() {}

        void Use(Ship* source, Ship* target) override;
};