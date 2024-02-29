#pragma once

#include "object.h"

class Cannon;
class Skill;
class Player;

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
    igniting_ship,
    random_ship,
    specter_ship,
    assassin_ship,
    development_ship,
    bomb_ship
};

enum Effect
{
    stunned_eff,
    shield_eff,
    immune_eff,
    suck_eff,
    heal_eff,
    fury_eff,
    dodge_eff,
    burn_eff,
    hide_eff,
    lock_eff,
    specter_eff
};

struct EffectInfo
{
    Effect type;
    int time;
};

enum Accessory
{
    time_bomb_acc,
    untime_bomb_acc,
    small_bomb_acc,
    big_bomb_acc
};

struct AccessoryInfo
{
    Accessory type;
    int time;
    string name;
};

class Ship : public Object
{
    public:
        Ship(Game* game, int id, Player* player);
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
        int GetRatioDamageReduce() const;
        void RoundHealth();

        vector<Cannon*> GetCannons() const;
        vector<Skill*> GetSkills() const;
        int GetNumCannons() const;
        int GetNumSkills() const;

        virtual void IncreaseHealth(double n);
        virtual void DecreaseHealth(double n, Ship* source);

        const vector<EffectInfo>& GetEffects() const;
        int FindEffect(Effect type) const;
        bool IncreaseEffect(Effect type, int time);
        void DecreaseEffect(Effect type, int time);
        void DeleteEffect(Effect type);
        void UpdateCurEffect();
        void UpdateOtherEffect(); // update lock
        void CheckEffects();

        const vector<AccessoryInfo>& GetAccessories() const;
        void AddAccessory(Accessory type);
        void UpdateAccessory();
        void DismantleBomb();
    
    protected:
        int id_;
        Player* player_;

        double max_health_;
        double health_;
        bool alive_;
        bool can_stunned_;
        int attack_times_; // default 1
        int dodge_prob_; // initial dodge probability, default 0
        int heal_health_; // the heal health in every round, default 0
        int absolute_damage_reduce_; // default 0
        int ratio_damage_reduce_; // default 0
        int shield_rebound_; // default 0
        ShipType ship_type_;
        vector<Cannon*> cannons_;
        vector<Skill*> skills_;

        vector<EffectInfo> effects_;
        vector<AccessoryInfo> accessories_;

        virtual void Ban();
        virtual void Update() {}
};