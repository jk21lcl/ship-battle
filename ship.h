#pragma once

#include "object.h"

class Cannon;
class Skill;

enum ShipType
{
    big_ship,
    middle_ship,
    small_ship,
    defense_ship,
    wizard_ship,
    heal_ship
};

class Ship : public Object
{
    public:
        Ship(Game* game);
        virtual ~Ship();

        double GetHealth() const;
        double GetMaxHealth() const;
        ShipType GetShipType() const;
        bool IsAlive() const;

        vector<Cannon*> GetCannons() const;
        vector<Skill*> GetSkills() const;
        int GetNumCannons() const;
        int GetNumSkills() const;

        virtual void IncreaseHealth(double n);
        virtual void DecreaseHealth(double n, Ship* source);

        int GetStunned() const;
        bool IsStunned() const;
        void IncreaseStun(int n);

        int GetShieldHealth() const;
        void IncreaseShieldHealth(int n);
        bool HasShield() const;

        int GetImmune() const;
        bool IsImmune() const;
        void IncreaseImmune(int n);

        int GetSuck() const;
        bool IsSuck() const;
        void IncreaseSuck(int n);

        int GetHeal() const;
        bool IsHeal() const;
        void IncreaseHeal(int n);
    
    protected:
        double max_health_;
        double health_;
        bool alive_;
        ShipType ship_type_;
        vector<Cannon*> cannons_;
        vector<Skill*> skills_;

        int stunned_;
        int shield_health_;
        int immune_;
        int suck_;
        int heal_;

        virtual void Ban() = 0;
};