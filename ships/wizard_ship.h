#pragma once

#include "ship.h"

class WizardShip : public Ship
{
    public:
        WizardShip(Game* game, int id);
        ~WizardShip() {}

        void Ban() override;
        void DecreaseHealth(double n, Ship* source) override;
};