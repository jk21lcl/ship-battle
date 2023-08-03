#pragma once

#include "ship.h"

class BigShip : public Ship   // health 20, attack 5
{
    public:
        BigShip(Game* game);
        ~BigShip() {}
};