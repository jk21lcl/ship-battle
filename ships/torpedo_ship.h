#pragma once

#include "ship.h"

class TorpedoShip : public Ship
{
    public:
        TorpedoShip(Game* game, int id);
        ~TorpedoShip() {}
};