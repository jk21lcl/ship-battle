#pragma once

#include "object.h"

enum ShipType
{
    big_ship,
    middle_ship,
    small_ship
};

class Ship : public Object
{
    public:
        Ship(Game* game);
        ~Ship() {}

        int GetHealth() const;
        void SetHealth(int health);
    
    protected:
        int health_;
        ShipType ship_type_;
};