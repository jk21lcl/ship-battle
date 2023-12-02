#pragma once

#include "ship.h"

class AssassinShip : public Ship
{
    public:
        AssassinShip(Game* game, int id);
        ~AssassinShip() {}

        void Update() override; // update the active state of skills
};