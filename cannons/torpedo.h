#pragma once

#include "cannon.h"

class Torpedo : public Cannon
{
    public:
        Torpedo(Game* game);
        ~Torpedo() {}

        void Attack(Ship* source, Ship* target) override;
};