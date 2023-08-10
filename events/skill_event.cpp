#include "skill_event.h"
#include "game.h"

SkillEvent::SkillEvent(Skill* skill, Ship* source, Ship* target)
{
    event_type_ = skill_event;
    skill_ = skill;
    source_ = source;
    target_ = target;
}

void SkillEvent::Process()
{
    skill_->Use(source_, target_);
}