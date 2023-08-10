#include "skill.h"
#include "game.h"

Skill::Skill(Game* game) : Object(game)
{
    object_type_ = skill;
    cd_ = 0;
}

void Skill::SetCd(int cd)
{
    cd_ = cd;
}

int Skill::GetCd() const
{
    return cd_;
}

bool Skill::IsReady() const
{
    return cd_ == 0;
}

SkillType Skill::GetSkillType() const
{
    return skill_type_;
}