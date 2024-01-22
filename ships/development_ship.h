#pragma once

#include "ship.h"

class DevelopmentShip : public Ship
{
    public:
        DevelopmentShip(Game* game, int id, Player* player);
        ~DevelopmentShip() {}

        int GetCritProb() const;
        void RandomUpdate();
    
    private:
        int crit_prob_;
};