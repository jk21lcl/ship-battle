#pragma once

#include "ship.h"

class SwiftShip : public Ship
{
    public:
        SwiftShip(Game* game, int id, Player* player);
        ~SwiftShip() {}
};