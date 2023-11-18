#include "skill.h"
#include "game.h"

Skill::Skill(Game* game) : Object(game)
{
    object_type_ = skill;
    cd_ = 0;
    skill_property_ = assist_skill;
    target_type_ = ally;
    attack_times_ = 1;
    crit_ = 1;
    dodge_ = 0;
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
        cout << source->GetId() << " \033[1;36m" << source->GetName() << "\033[0m ";
        cout << "made a " << "\033[0;33m" << crit_ << "\033[0m" << " crit to ";
        cout << target->GetId() << " \033[1;36m" << target->GetName() << "\033[0m ";
        cout << endl;
    }
}

bool Skill::ProcessDodge(Ship* source, Ship* target)
{
    dodge_ = 0;
    if (target->GetShipType() == swift_ship)
        dodge_ += 25;
    if (target->IsDodge())
        dodge_ += 25;
    int random = rand() % 100;
    if (random < dodge_)
    {
        cout << source->GetId() << " \033[1;36m" << source->GetName() << "\033[0m";
        cout << "'s attack is dodged by ";
        cout << target->GetId() << " \033[1;36m" << target->GetName() << "\033[0m";
        cout << endl;
        return true;
    }
    return false;
}