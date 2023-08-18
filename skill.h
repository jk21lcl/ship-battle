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
    fury
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
    
    protected:
        SkillType skill_type_;
        int cd_;
};