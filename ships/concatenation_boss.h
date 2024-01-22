#pragma once

#include "ship.h"

class ConcatenationBoss : public Ship
{
    public:
        ConcatenationBoss(Game* game, int id, Player* player);
        ~ConcatenationBoss() {}

        void Update() override; // update damage_reduce data
};