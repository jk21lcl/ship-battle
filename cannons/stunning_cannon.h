#pragma once

#include "cannon.h"

class StunningCannon : public Cannon
{
    public:
        StunningCannon(Game* game);
        ~StunningCannon() {}

        void Attack(Ship* source, Ship* target) override;
};