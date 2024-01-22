#pragma once

#include "ship.h"

class DefenseShip : public Ship
{
    public:
        DefenseShip(Game* game, int id, Player* player);
        ~DefenseShip() {}

        void Update() override; // update the damage_reduce data
};