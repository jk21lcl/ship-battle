#pragma once

#include "cannon.h"

class SpecterCannon : public Cannon
{
    public:
        SpecterCannon(Game* game);
        ~SpecterCannon() {}

        void Attack(Ship* source, Ship* target) override;
};