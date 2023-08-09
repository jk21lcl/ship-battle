#pragma once

#include "cannon.h"

class SplitCannon : public Cannon
{
    public:
        SplitCannon(Game* game);
        ~SplitCannon() {}
    
        void Attack(Ship* source, Ship* target) override;
};