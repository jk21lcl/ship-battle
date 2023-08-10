#pragma once

#include "event.h"

class SkillEvent : public Event
{
    public:
        SkillEvent(Skill* skill, Ship* source, Ship* target);
        ~SkillEvent() {}

        void Process() override;
    
    private:
        Skill* skill_;
};