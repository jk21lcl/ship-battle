#pragma once

#include "cannon.h"

class CritCannon : public Cannon
{
    public:
        CritCannon(Game* game);
        ~CritCannon() {}

        void Attack(Ship* source, Ship* target) override;
        void ProcessCrit(Ship* source) override;
};