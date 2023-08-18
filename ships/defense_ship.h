#pragma once

#include "ship.h"

class DefenseShip : public Ship
{
    public:
        DefenseShip(Game* game, int id);
        ~DefenseShip() {}

        void Ban() override;
        void DecreaseHealth(double n, Ship* source) override;
};