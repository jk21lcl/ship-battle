#pragma once

#include "ship.h"

class TorpedoShip : public Ship   // health 20, attack 5
{
    public:
        TorpedoShip(Game* game, int id);
        ~TorpedoShip() {}
};