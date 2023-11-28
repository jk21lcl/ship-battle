#pragma once

#include "cannon.h"

class BiasedCannon : public Cannon
{
    public:
        BiasedCannon(Game* game);
        ~BiasedCannon() {}

        void Attack(Ship* source, Ship* target) override;
    
    private:
        void OutputTarget(Ship* source, Ship* target) const;
};