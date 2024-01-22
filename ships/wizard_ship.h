#pragma once

#include "ship.h"

class WizardShip : public Ship
{
    public:
        WizardShip(Game* game, int id, Player* player);
        ~WizardShip() {}
};