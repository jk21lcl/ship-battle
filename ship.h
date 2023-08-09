#pragma once

#include "object.h"

class Cannon;

enum ShipType
{
    big_ship,
    middle_ship,
    small_ship,
    defense_ship
};

class Ship : public Object
{
    public:
        Ship(Game* game);
        virtual ~Ship();

        double GetHealth() const;
        double GetMaxHealth() const;
        vector<Cannon*> GetCannons() const;
        ShipType GetShipType() const;
        bool IsAlive() const;

        int GetStunned() const;
        bool IsStunned() const;
        void IncreaseStun(int n);

        virtual void IncreaseHealth(double n);
        virtual void DecreaseHealth(double n, Ship* source);

        int GetShieldHealth() const;
        void IncreaseShieldHealth(int n);
        bool HasShield() const;
    
    protected:
        double max_health_;
        double health_;
        bool alive_;
        int stunned_;
        ShipType ship_type_;
        vector<Cannon*> cannons_;
        int shield_health_;

        virtual void Ban() = 0;
};