#pragma once

#include "ship.h"

class SmallExplosiveShip : public Ship
{
    public:
        SmallExplosiveShip(Game* game, int id);
        ~SmallExplosiveShip() {}
    
        void Ban() override {}
};