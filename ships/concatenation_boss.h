#pragma once

#include "ship.h"

class ConcatenationBoss : public Ship   // health 20, attack 5
{
    public:
        ConcatenationBoss(Game* game, int id);
        ~ConcatenationBoss() {}

        void DecreaseHealth(double n, Ship* source) override;
};