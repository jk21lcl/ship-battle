#pragma once

#include "skill.h"

class MediumExplode : public Skill
{
    public:
        MediumExplode(Game* game);
        ~MediumExplode() {}

        void Use(Ship* source, Ship* target) override;
};