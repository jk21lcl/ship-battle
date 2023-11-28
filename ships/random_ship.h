#pragma once

#include "ship.h"

class RandomShip : public Ship   // health 20, attack 5
{
    public:
        RandomShip(Game* game, int id);
        ~RandomShip() {}
};