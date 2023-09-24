#pragma once

#include "object.h"

class Ship;

enum SkillType
{
    shield,
    immune,
    suck,
    heal,
    super_heal,
    fury,
    dodge,
    super_shield,
    grapeshot,
    super_grapeshot,
    small_explode,
    medium_explode,
    big_explode
};

class Skill : public Object
{
    public:
        Skill(Game* game);
        virtual ~Skill() {}

        virtual void Use(Ship* source, Ship* target) = 0;
        void SetCd(int cd);
        int GetCd() const;
        bool IsReady() const;
        SkillType GetSkillType() const;

        virtual void ProcessCrit(Ship* source, Ship* target);
        void OutputCrit(Ship* source, Ship* target) const;
        bool ProcessDodge(Ship* source, Ship* target);
    
    protected:
        SkillType skill_type_;
        int cd_;
        double crit_;
        int dodge_;
};