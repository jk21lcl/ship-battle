#pragma once

#include "ship.h"

class CritShip : public Ship
{
    public:
        CritShip(Game* game, int id);
        ~CritShip() {}
};