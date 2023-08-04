#pragma once

#include "ship.h"

class SmallShip : public Ship   // health 5, attack 2
{
    public:
        SmallShip(Game* game);
        ~SmallShip() {}
    
        void Ban() override;
};