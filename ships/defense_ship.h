#pragma once

#include "ship.h"

class DefenseShip : public Ship
{
    public:
        DefenseShip(Game* game, int id);
        ~DefenseShip() {}
        
        void DecreaseHealth(double n, Ship* source) override;
};