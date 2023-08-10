#pragma once

#include "event.h"

class ExplosiveEvent : public Event
{
    public:
        ExplosiveEvent(Cannon* cannon, Ship* source, Ship* target,
                       Ship* splash_tar_1, Ship* splash_tar_2);
        ~ExplosiveEvent() {}

        void Process() override;
    
    private:
        Cannon* cannon_;
        Ship* splash_tar_1_;
        Ship* splash_tar_2_;
};