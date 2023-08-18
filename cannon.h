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
    super_crit_cannon
};

class Cannon : public Object
{
    public:
        Cannon(Game* game);
        virtual ~Cannon() {}

        virtual void Attack(Ship* source, Ship* target) = 0;
        void SetCd(int cd);
        int GetCd() const;
        bool IsReady() const;
        bool IsAvailable() const;
        void Ban();
        CannonType GetCannonType() const;
        virtual void ProcessCrit(Ship* source);
        void OutputCrit(Ship* source) const;
        bool ProcessDodge(Ship* source, Ship* target);
    
    protected:
        CannonType cannon_type_;
        int cd_;
        bool available_;
        double crit_;
        int dodge_;
};