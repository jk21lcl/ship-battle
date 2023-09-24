#pragma once

#include "cannon.h"

class SplitCannon : public Cannon
{
    public:
        SplitCannon(Game* game);
        ~SplitCannon() {}
    
        void Attack(Ship* source, Ship* target) override;
        void ProcessCrit(Ship* source, Ship* target) override;
    
    private:
        int crit_count_;
};