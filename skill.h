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
    big_explode,
    ignite,
    blow,
    random_buff
};

enum SkillProperty
{
    assist_skill,
    attack_skill
};

class Skill : public Object
{
    public:
        Skill(Game* game);
        virtual ~Skill() {}

        virtual void Use(Ship* source, Ship* target) = 0;
        void SetCd(int cd);
        int GetCd() const;
        int GetMaxCd() const;
        bool IsReady() const;
        SkillType GetSkillType() const;
        SkillProperty GetSkillProperty() const;
        TargetType GetTargetType() const;
        int GetAttackTimes() const;

        bool IsAvailable() const;
        void Ban();

        void ProcessCrit(Ship* source, Ship* target);
        void OutputCrit(Ship* source, Ship* target) const;
        bool ProcessDodge(Ship* source, Ship* target);
    
    protected:
        SkillType skill_type_;
        int cd_;
        int max_cd_;
        bool available_;
        double crit_;
        int dodge_;

        SkillProperty skill_property_; // default assist_skill
        TargetType target_type_; // default ally
        int attack_times_; // default 1
};