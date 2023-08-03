#pragma once

#include "cannon.h"

class Cannon2 : public Cannon
{
    public:
        Cannon2(Game* game);
        ~Cannon2() {}

        void Attack(Ship* source, Ship* target) override;
};