#pragma once

class Ship;
class Cannon;
class Skill;

enum EventType
{
    cannon_event,
    skill_event,
    dismantle_bomb_event
};

class Event
{
    public:
        Event() {}
        virtual ~Event() {}

        virtual void Process() = 0;
    
    protected:
        EventType event_type_;
        Ship* source_;
        Ship* target_;
};