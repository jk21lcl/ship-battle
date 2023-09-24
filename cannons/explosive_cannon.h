#pragma once

#include "cannon.h"

class ExplosiveCannon : public Cannon
{
    public:
        ExplosiveCannon(Game* game);
        ~ExplosiveCannon() {}

        void Attack(Ship* source, Ship* target) override;
};