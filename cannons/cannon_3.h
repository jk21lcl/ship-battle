#pragma once

#include "cannon.h"

class Cannon3 : public Cannon
{
    public:
        Cannon3(Game* game);
        ~Cannon3() {}

        void Attack(Ship* source, Ship* target) override;
};