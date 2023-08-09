#pragma once

#include "ship.h"

class WizardShip : public Ship
{
    public:
        WizardShip(Game* game);
        ~WizardShip() {}

        void Ban() override;
        void DecreaseHealth(double n, Ship* source) override;
};