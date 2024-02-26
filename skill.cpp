#include "skill.h"
#include "game.h"

Skill::Skill(Game* game) : Object(game)
{
    object_type_ = skill;
    cd_ = 0;
    available_ = true;
    just_used_ = false;
    skill_property_ = assist_skill;
    target_type_ = ally;
    attack_times_ = 1;
    crit_ = 1;
    dodge_ = 0;
    active_ = true;
}

void Skill::SetCd(int cd)
{
    cd_ = cd;
}

int Skill::GetCd() const
{
    return cd_;
}

int Skill::GetMaxCd() const
{
    return max_cd_;
}

bool Skill::IsReady() const
{
    return cd_ == 0;
}

bool Skill::IsAvailable() const
{
    return available_;
}

void Skill::Ban()
{
    available_ = false;
}

SkillType Skill::GetSkillType() const
{
    return skill_type_;
}

SkillProperty Skill::GetSkillProperty() const
{
    return skill_property_;
}

TargetType Skill::GetTargetType() const
{
    return target_type_;
}

int Skill::GetAttackTimes() const
{
    return attack_times_;
}

bool Skill::IsActive() const
{
    return active_;
}

void Skill::SetActive(bool active)
{
    active_ = active;
}

bool Skill::IsJustUsed() const
{
    return just_used_;
}

void Skill::SetJustUsed(bool just_used)
{
    just_used_ = just_used;
}

void Skill::ProcessCrit(Ship* source, Ship* target)
{
    if (source->IsFury())
    {
        crit_ = 2;
        source->IncreaseFury(-1);
    }
    else
        crit_ = 1;
}

void Skill::OutputCrit(Ship* source, Ship* target) const
{
    if (crit_ != 1)
    {
        cout << source->GetId() << " \033[1;36m" << source->GetName() << "\033[0m";
        cout << "'s " << "\033[0;33m" << name_ << "\033[0m";
        cout << " made a " << "\033[0;33m" << crit_ << "\033[0m" << " crit to ";
        cout << target->GetId() << " \033[1;36m" << target->GetName() << "\033[0m";
        cout << endl;
    }
}

bool Skill::ProcessDodge(Ship* source, Ship* target)
{
    if (target->IsLock())
        dodge_ = 0;
    else if (target->IsHide())
        dodge_ = 100;
    else 
    {
        dodge_ = target->GetDodgeProb();
        if (target->IsDodge())
            dodge_ += 25;
    }
    int random = rand() % 100;
    if (random < dodge_)
    {
        cout << source->GetId() << " \033[1;36m" << source->GetName() << "\033[0m";
        cout << "'s " << "\033[0;33m" << name_ << "\033[0m" << " is dodged by ";
        cout << target->GetId() << " \033[1;36m" << target->GetName() << "\033[0m";
        cout << endl;
        return true;
    }
    return false;
}