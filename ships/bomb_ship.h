#pragma once

#include "ship.h"

class BombShip : public Ship
{
    public:
        BombShip(Game* game, int id, Player* player);
        ~BombShip() {}

        void Bomb();
};