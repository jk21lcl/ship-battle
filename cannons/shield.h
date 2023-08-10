#pragma once

#include "cannon.h"

class Shield : public Cannon
{
    public:
        Shield(Game* game);
        ~Shield() {}

        void Attack(Ship* source, Ship* target) override;
};