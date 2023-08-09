#pragma once

#include "cannon.h"

class ExplosiveCannon : public Cannon
{
    public:
        ExplosiveCannon(Game* game);
        ~ExplosiveCannon() {}

        void Attack(Ship* source, Ship* target) override {}
        void SpecialAttack(Ship* source, Ship* main_target, Ship* splash_target_1, 
                           Ship* splash_target_2);
};