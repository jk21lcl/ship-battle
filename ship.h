#pragma once

#include "object.h"

class Cannon;

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
        virtual ~Ship();

        int GetHealth() const;
        void SetHealth(int health);
        vector<Cannon*> GetCannons() const;
        bool IsAlive() const;
    
    protected:
        int health_;
        bool alive_;
        ShipType ship_type_;
        vector<Cannon*> cannons_;

        virtual void Ban() = 0;
};