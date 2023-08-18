#pragma once

#include "ship.h"

class MiddleShip : public Ship    // health 10, attack 3
{
    public:
        MiddleShip(Game* game, int id);
        ~MiddleShip() {}
    
        void Ban() override;
};