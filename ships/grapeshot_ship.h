#pragma once

#include "ship.h"

class GrapeshotShip : public Ship
{
    public:
        GrapeshotShip(Game* game, int id);
        ~GrapeshotShip() {}
    
        void Ban() override;
};