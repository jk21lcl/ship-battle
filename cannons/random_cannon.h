#pragma once

#include "cannon.h"

class RandomCannon : public Cannon
{
    public:
        RandomCannon(Game* game);
        ~RandomCannon() {}

        void Attack(Ship* source, Ship* target) override;
};