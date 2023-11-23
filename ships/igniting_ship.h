#pragma once

#include "ship.h"

class IgnitingShip : public Ship
{
    public:
        IgnitingShip(Game* game, int id);
        ~IgnitingShip() {}
};