#pragma once

#include "ship.h"

class SpecterShip : public Ship
{
    public:
        SpecterShip(Game* game, int id, Player* player);
        ~SpecterShip() {}

        int GetSpecter() const;
        bool IsSpecter() const;
        void IncreaseSpecter(int n);

        void Update() override; // update dodge_prob_ and damage_reduce_
    
    private:
        int specter_;
};