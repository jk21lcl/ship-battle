#include "cannon_event.h"
#include "game.h"

CannonEvent::CannonEvent(Cannon* cannon, Ship* source, Ship* target)
{
    event_type_ = cannon_event;
    cannon_ = cannon;
    source_ = source;
    target_ = target;
}

void CannonEvent::Process()
{
    cannon_->Attack(source_, target_);
}