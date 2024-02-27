#include "dismantle_bomb_event.h"
#include "game.h"

DismantleBombEvent::DismantleBombEvent(Ship* source)
{
    event_type_ = dismantle_bomb_event;
    source_ = source;
}

void DismantleBombEvent::Process()
{
    source_->DismantleBomb();
}