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
    heal_ship,
    crit_ship,
    swift_ship,
    grapeshot_ship,
    small_explosive_ship,
    medium_explosive_ship,
    big_explosive_ship,
    torpedo_ship,
    concatenation_boss,
    igniting_ship
};

class Ship : public Object
{
    public:
        Ship(Game* game, int id);
        virtual ~Ship();

        double GetHealth() const;
        double GetMaxHealth() const;
        ShipType GetShipType() const;
        bool IsAlive() const;
        void SetDead();
        int GetId() const;
        bool GetCanStunned() const;
        int GetAttackTimes() const;
        int GetDodgeProb() const;
        int GetHealHealth() const;

        vector<Cannon*> GetCannons() const;
        vector<Skill*> GetSkills() const;
        int GetNumCannons() const;
        int GetNumSkills() const;

        virtual void IncreaseHealth(double n);
        virtual void DecreaseHealth(double n, Ship* source);

        int GetStunned() const;
        bool IsStunned() const;
        bool IncreaseStun(int n);

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

        int GetFury() const;
        bool IsFury() const;
        void IncreaseFury(int n);

        int GetDodge() const;
        bool IsDodge() const;
        void IncreaseDodge(int n);

        int GetBurn() const;
        bool IsBurn() const;
        void IncreaseBurn(int n);
    
    protected:
        int id_;

        double max_health_;
        double health_;
        bool alive_;
        bool can_stunned_;
        int attack_times_; // default 1
        int dodge_prob_; // initial dodge probability, default 0
        int heal_health_; // the heal health in every round, default 0
        ShipType ship_type_;
        vector<Cannon*> cannons_;
        vector<Skill*> skills_;

        int stunned_;
        int shield_health_;
        int immune_;
        int suck_;
        int heal_;
        int fury_;
        int dodge_;
        int burn_;

        void Ban();
};