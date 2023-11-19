#pragma once

#include "ship.h"

class BigExplosiveShip : public Ship
{
    public:
        BigExplosiveShip(Game* game, int id);
        ~BigExplosiveShip() {}
};