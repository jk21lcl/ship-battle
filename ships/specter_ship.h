#pragma once

#include "ship.h"

class SpecterShip : public Ship
{
    public:
        SpecterShip(Game* game, int id, Player* player);
        ~SpecterShip() {}

        void Update() override; // update dodge_prob_ and damage_reduce_
};