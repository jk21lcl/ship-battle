#pragma once

#include "cannon.h"

class Cannon5 : public Cannon
{
    public:
        Cannon5(Game* game);
        ~Cannon5() {}

        void Attack(Ship* source, Ship* target) override;
};