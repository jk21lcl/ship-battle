#pragma once

#include "ship.h"

class WizardShip : public Ship
{
    public:
        WizardShip(Game* game, int id);
        ~WizardShip() {}
};