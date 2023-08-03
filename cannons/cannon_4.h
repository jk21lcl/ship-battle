#pragma once

#include "cannon.h"

class Cannon4 : public Cannon
{
    public:
        Cannon4(Game* game);
        ~Cannon4() {}

        void Attack(Ship* source, Ship* target) override;
};