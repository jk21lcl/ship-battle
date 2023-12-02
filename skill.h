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
    random_buff,
    specter,
    hide,
    specter_explode,
    super_specter_explode,
    sacrifice,
    lock,
    stab
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
        bool IsJustUsed() const;
        void SetJustUsed(bool just_used);
        bool IsActive() const;
        void SetActive(bool active);

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
        bool just_used_; // whether it is used in this round
        double crit_;
        int dodge_;
        bool active_;

        SkillProperty skill_property_; // default assist_skill
        TargetType target_type_; // default ally
        int attack_times_; // default 1
};