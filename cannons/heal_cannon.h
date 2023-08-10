#pragma once

#include "cannon.h"

class HealCannon : public Cannon
{
    public:
        HealCannon(Game* game);
        ~HealCannon() {}

        void Attack(Ship* source, Ship* target) override;
};