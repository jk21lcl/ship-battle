#pragma once

#include "object.h"

class Ship;

enum SkillType
{
    shield
};

class Skill : public Object
{
    public:
        Skill(Game* game);
        virtual ~Skill() {}

        virtual void Attack(Ship* source, Ship* target) = 0;
        void SetCd(int cd);
        int GetCd() const;
        bool IsReady() const;
        SkillType GetSkillType() const;
    
    protected:
        SkillType skill_type_;
        int cd_;
};