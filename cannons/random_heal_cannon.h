#pragma once

#include "cannon.h"

class RandomHealCannon : public Cannon
{
    public:
        RandomHealCannon(Game* game);
        ~RandomHealCannon() {}

        void Attack(Ship* source, Ship* target) override;
};