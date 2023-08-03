#pragma once

#include "cannon.h"

class Cannon1 : public Cannon
{
    public:
        Cannon1(Game* game);
        ~Cannon1() {}

        void Attack(Ship* source, Ship* target) override;
};