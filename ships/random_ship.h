#pragma once

#include "ship.h"

class RandomShip : public Ship
{
    public:
        RandomShip(Game* game, int id, Player* player);
        ~RandomShip() {}
};