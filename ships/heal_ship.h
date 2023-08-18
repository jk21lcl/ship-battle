#pragma once

#include "ship.h"

class HealShip : public Ship
{
    public:
        HealShip(Game* game, int id);
        ~HealShip() {}

        void Ban() override {}
};