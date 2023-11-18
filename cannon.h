#pragma once

#include "object.h"

class Ship;

enum CannonType
{
    cannon_1,
    cannon_2,
    cannon_3,
    cannon_4,
    cannon_5,
    split_cannon,
    stunning_cannon,
    explosive_cannon,
    heal_cannon,
    crit_cannon,
    super_crit_cannon,
    torpedo
};

class Cannon : public Object
{
    public:
        Cannon(Game* game);
        virtual ~Cannon() {}

        virtual void Attack(Ship* source, Ship* target) = 0;
        void SetCd(int cd);
        int GetCd() const;
        int GetMaxCd() const;
        bool IsReady() const;
        CannonType GetCannonType() const;
        TargetType GetTargetType() const;
        int GetAttackTimes() const;

        bool IsAvailable() const;
        void Ban();

        virtual void ProcessCrit(Ship* source, Ship* target);
        void OutputCrit(Ship* source, Ship* target) const;
        bool ProcessDodge(Ship* source, Ship* target);
    
    protected:
        CannonType cannon_type_;
        int cd_;
        int max_cd_;
        bool available_;
        double crit_;
        int dodge_;

        TargetType target_type_; // default enemy
        int attack_times_; // default 1
};