#pragma once

#include "cannon.h"

class SuperCritCannon : public Cannon
{
    public:
        SuperCritCannon(Game* game);
        ~SuperCritCannon() {}

        void Attack(Ship* source, Ship* target) override;
        void ProcessCrit(Ship* source) override;
};