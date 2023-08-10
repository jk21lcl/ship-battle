#pragma once

#include "event.h"

class CannonEvent : public Event
{
    public:
        CannonEvent(Cannon* cannon, Ship* source, Ship* target);
        ~CannonEvent() {}

        void Process() override;
    
    private:
        Cannon* cannon_;
};