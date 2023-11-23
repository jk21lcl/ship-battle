#pragma once

#include "cannon.h"

class BurningCannon : public Cannon
{
    public:
        BurningCannon(Game* game);
        ~BurningCannon() {}

        void Attack(Ship* source, Ship* target) override;
};