#pragma once

#include "event.h"

class DismantleBombEvent : public Event
{
    public:
        DismantleBombEvent(Ship* source);
        ~DismantleBombEvent() {}

        void Process() override;
};