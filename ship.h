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

        double GetHealth() const;
        void SetHealth(double health);
        double GetMaxHealth() const;
        vector<Cannon*> GetCannons() const;
        bool IsAlive() const;
        bool IsSkipped() const;
        void SetSkip(bool skipped);
    
    protected:
        double max_health_;
        double health_;
        bool alive_;
        bool skipped_;
        ShipType ship_type_;
        vector<Cannon*> cannons_;

        virtual void Ban() = 0;
};