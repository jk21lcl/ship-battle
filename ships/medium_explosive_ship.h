#pragma once

#include "ship.h"

class MediumExplosiveShip : public Ship
{
    public:
        MediumExplosiveShip(Game* game, int id, Player* player);
        ~MediumExplosiveShip() {}
};